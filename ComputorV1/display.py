import sys
import settings
import solving


def polynomial_degree_err():
    print('\nThe polynomial degree is strictly greater than 2, I can\'t solve.')
    sys.exit(1)


def syntax_err():
    print('\nSyntaxError: Please correctly enter a polynomial')
    print('Here\'s some examples:')
    print('ax2 + bx + c = 0         ;   bX - c = aX2')
    print('a * X2 + b * X1 + c = 0  ;   b * x^2 + a * x^2 = c * x^0')
    sys.exit(2)


def no_solution():
    print('\nReduced form:', str(settings.c), '= 0')
    print('Impossible equation: There is no solution.')
    sys.exit(1)


def infinite_solutions():
    print("\nEvery x coefficient is equal to 0, which means the polynomial degree is 0, there are infinite solutions.")
    sys.exit(1)


def reduced_form():
    a = settings.a
    b = settings.b
    c = settings.c

    print("\nReduced form: ", end="")
    if a:
        if a == 1:
            print("x²", end="")
        elif a == -1:
            print("-x²", end="")
        else:
            print(str(a) + "x²", end="")
    if b:
        if a:
            if b < 0:
                if b == -1:
                    print(" -", "x", end="")
                else:
                    print(" -", str(b * -1) + "x", end="")
            else:
                if b == 1:
                    print(" +", "x", end="")
                else:
                    print(" +", str(b) + "x", end="")
        else:
            if b == 1:
                print("x", end="")
            else:
                print(str(b) + "x", end="")
    if c:
        if c < 0:
            print(" -", str(c * -1), end="")
        else:
            print(" +", str(c), end="")
    print(" = 0")
    print('a =', a, '; b =', b, '; c =', c)


def polynomial_degree():
    print('Polynomial degree: ', end='')
    if settings.a:
        print('2\n')
    else:
        print('1\n')


def delta():
    print('Δ = b² - 4 * a * c')
    print('  =', str(settings.b) + '² - 4 *', str(settings.a), '*', str(settings.c))
    print('  =', str(settings.b * settings.b), '-', str(4 * settings.a * settings.c))
    print('  =', settings.delta)
    if settings.delta < 0:
        print('Discriminant is strictly negative.')
    elif settings.delta == 0:
        print('Discriminant equals to zero.')
    else:
        print('Discriminant is strictly positive.')


def negative_delta_solution(first, root, b_quotient, res):

    if first:
        name = 'x1'
        operator = '+'
    else:
        name = '\nx2'
        operator = '-'

    length = len(str(res / (2 * settings.a)))

    print(name, '= (-b', operator, 'i * √|Δ|) / 2a')
    print('   = (' + str(settings.b * -1), operator, 'i * √' + str(settings.delta * -1) + ') /', str(2 * settings.a))
    if root[0] == '√':
        if settings.b == 0:
            print('   =', 'i *' if first else '-i *', root, '/', str(2 * settings.a))
        else:
            print('   =', b_quotient, operator, 'i *', root, '/', str(2 * settings.a))
    elif length <= 4 or (length <= 5 and res / (2 * settings.a) < 0):
        if settings.b == 0:
            print('   =', 'i *' if first else '-i *', str(res / (2 * settings.a)))
        else:
            print('   =', b_quotient, operator, 'i *', str(res / (2 * settings.a)))
    else:
        if settings.b == 0:
            print('   =', 'i *' if first else '-i *', solving.reduced_fraction(res, 2 * settings.a))
        else:
            print('   =', b_quotient, operator, 'i *', solving.reduced_fraction(res, 2 * settings.a))


def positive_delta_solution(first, root, b_quotient, res):

    if first:
        name = 'x1'
        operator = '+'
    else:
        name = '\nx2'
        operator = '-'

    length2 = len(str((settings.b * -1 + res) / (2 * settings.a)))
    length3 = len(str((settings.b * -1 - res) / (2 * settings.a)))

    print(name, '= (-b', operator, '√Δ) / 2a')
    print('   = (' + str(settings.b * -1), operator, '√' + str(settings.delta) + ') /', str(2 * settings.a))
    if root[0] == '√':
        if settings.b == 0:
            print('   =', root if first else '-' + root, '/', str(2 * settings.a))
        else:
            print('   =', b_quotient, operator, root, '/', str(2 * settings.a))
    elif first:
        if length2 <= 5 or (length2 <= 6 and (settings.b * -1 + res) / (2 * settings.a) < 0):
            print('   =', str((settings.b * -1 + res) / (2 * settings.a)))
        else:
            print('   =', solving.reduced_fraction(settings.b * -1 + res, 2 * settings.a))
    else:
        if length3 <= 5 or (length3 <= 6 and (settings.b * -1 - res) / (2 * settings.a) < 0):
            print('   =', str((settings.b * -1 - res) / (2 * settings.a)))
        else:
            print('   =', solving.reduced_fraction(settings.b * -1 - res, 2 * settings.a))
