import argparse
import sys
import settings
import display


def degrees_checks():
    for k, v in settings.degrees.items():
        print('\n\nk =', k, 'v =', v, '\n\n')
        if v != 0:
            display.polynomial_degree_err()


def assign_value(value, signed):
    if signed:
        return value * -1
    return value


def x_case(s, index, value, signed, equal):
    i = index
    degree = 0

    if i + 1 >= len(s) or not s[i + 1].isdigit():
        if equal:
            settings.bp += assign_value(value, signed)
        else:
            settings.b += assign_value(value, signed)
        return
    i += 1

    while i < len(s) and s[i].isdigit():
        degree = degree * 10 + int(s[i])
        i += 1

    if degree == 2:
        if equal:
            settings.ap += assign_value(value, signed)
        else:
            settings.a += assign_value(value, signed)
    elif degree == 1:
        if equal:
            settings.bp += assign_value(value, signed)
        else:
            settings.b += assign_value(value, signed)
    elif degree == 0:
        if equal:
            settings.cp += assign_value(value, signed)
        else:
            settings.c += assign_value(value, signed)
    else:
        v = value
        if signed:
            v = v * -1
        if equal:
            v = v * -1
        if degree in settings.degrees:
            settings.degrees[degree] += v
        else:
            settings.degrees[degree] = v


def parse_equation(args):
    value = 0
    number = -1
    equal = False
    signed = False
    stored = False
    decimals = 0
    s = args.replace('^', '')

    for i in range(len(s)):
        if s[i] == '=' or s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == ' ' or s[i] == '.':
            if s[i] == '=' or s[i] == '+' or s[i] == '-':
                if number == -1 and s[i] != '-':
                    display.syntax_err()
                if not stored:
                    if equal:
                        if s[i] == '=':
                            display.syntax_err()
                        settings.cp += assign_value(value, signed)
                    else:
                        settings.c += assign_value(value, signed)
                value = 0
                number = -1
                decimals = 0
                stored = False
            if s[i] == '=':
                equal = True
                signed = False
            elif s[i] == '+':
                signed = False
            elif s[i] == '-':
                signed = True
            elif s[i] == '*':
                if number == -1 or number == 0 or stored:
                    display.syntax_err()
                number = 0

        elif s[i].isdigit() and not stored:
            if number == 0:
                display.syntax_err()
            if decimals == 0:
                value = value * 10 + int(s[i])
                number = 1
            else:
                value = value + int(s[i]) / (10 ** decimals)
                decimals += 1
            if i + 1 >= len(s):
                settings.cp += assign_value(value, signed)

        elif s[i] == '.':
            if decimals > 0 or number != 1:
                display.syntax_err()
            decimals = 1

        elif s[i] == 'x' or s[i] == 'X':
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

    degrees_checks()

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
