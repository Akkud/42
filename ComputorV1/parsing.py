import argparse
import sys
import settings
import display


def power_checks(s, i):
    if i + 1 < len(s) and s[i + 1].isdigit():
        if '3' <= s[i + 1] <= '9' or (i + 2 < len(s) and s[i + 2].isdigit()):
            display.polynomial_degree_err()
    if i + 1 < len(s) and s[i + 1] == '^':
        if i + 2 >= len(s) or not s[i + 2].isdigit():
            display.syntax_err()
        elif i + 2 < len(s) and s[i + 1].isdigit():
            if '3' <= s[i + 1] <= '9' or (i + 3 < len(s) and s[i + 2].isdigit()):
                display.polynomial_degree_err()


def assign_value(value, signed):
    if signed:
        return value * -1
    return value


def x_case(s, i, value, signed, equal):
    if i + 1 < len(s):
        if s[i + 1] == '2' or s[i + 1] == '²' or (s[i + 1] == '^' and s[i + 2] == '2'):
            if equal:
                settings.ap += assign_value(value, signed)
            else:
                settings.a += assign_value(value, signed)
        elif s[i + 1] == '1' or (s[i + 1] == '^' and s[i + 2] == '1') or not s[i + 1].isdigit():
            if equal:
                settings.bp += assign_value(value, signed)
            else:
                settings.b += assign_value(value, signed)
        elif s[i + 1] == '0' or (s[i + 1] == '^' and s[i + 2] == '0'):
            if equal:
                settings.cp += assign_value(value, signed)
            else:
                settings.c += assign_value(value, signed)
    else:
        settings.bp += assign_value(value, signed)


def parse_equation(s):
    value = 0
    number = -1
    equal = False
    signed = False
    stored = False

    for i in range(len(s)):
        if s[i] == '=' or s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == ' ':
            if s[i] != '*' and s[i] != ' ':
                if number == -1 and s[i] != '-':
                    display.syntax_err()
                if not stored:
                    if equal:
                        settings.cp += assign_value(value, signed)
                    else:
                        settings.c += assign_value(value, signed)
                value = 0
                number = -1
                stored = False
            if s[i] == '=':
                equal = True
                signed = False
            elif s[i] == '+':
                signed = False
            elif s[i] == '-':
                signed = True
            elif s[i] == '*':
                if number == -1 or number == 0:
                    display.syntax_err()
                number = 0

        elif s[i].isdigit():
            if number == 0:
                display.syntax_err()
            else:
                value = value * 10 + ord(s[i]) - 48
                number = 1
            if i + 1 >= len(s) and not stored:
                settings.cp += assign_value(value, signed)

        elif s[i] == 'x' or s[i] == 'X':
            power_checks(s, i)
            if value == 0:
                if number == -1:
                    value = 1
                    number = 1
            x_case(s, i, value, signed, equal)
            stored = True
    if not equal:
        display.syntax_err()

    settings.a = settings.a - settings.ap
    settings.b = settings.b - settings.bp
    settings.c = settings.c - settings.cp

    if not settings.a and not settings.b:
        if settings.c:
            display.no_solution()
        display.infinite_solutions()


def start():
    parser = argparse.ArgumentParser(description="Solves equations")

    parser.add_argument('equation', metavar='a*X^2 + b*X^1 = c*X^0', type=str, nargs='+',
                        help='Polynomial up to degree 2')

    args = parser.parse_args()

    if args.equation is None:
        print('Please enter a polynomial or try the -h option for help')
        sys.exit(0)

    parse_equation(" ".join(args.equation))
