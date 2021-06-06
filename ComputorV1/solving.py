import settings
import display


def reduced_fraction(numerator, denominator):
    res = ''
    if numerator < 0 and denominator < 0:
        numerator = numerator * -1
        denominator = denominator * -1
    elif numerator < 0:
        numerator = numerator * -1
        res = '-'
    elif denominator < 0:
        denominator = denominator * -1
        res = '-'

    smallest = numerator if numerator <= denominator else denominator
    for i in range(smallest, 1, -1):
        if numerator % i == 0 and denominator % i == 0:
            if numerator % 1 == 0 and denominator % 1 == 0:
                return res + str(int(numerator / i)) + '/' + str(int(denominator / i))
            return res + str(numerator / i) + '/' + str(denominator / i)
    return res + str(numerator) + '/' + str(denominator)


def square_root(nbr):
    if nbr == 1:
        return 1
    for i in range(2, nbr // 2 + 1):
        if i * i == nbr:
            return i
    return 0


def normal_solving():
    res = 0
    if settings.c:
        res = settings.c * -1
        print('\nStep 1:\n' + str(settings.b) + 'x', '=', str(settings.c * -1))
    length = len(str(res / settings.b))
    if length <= 4 or (length <= 5 and res / settings.b < 0):
        print('\nThe solution is:\n' + str(res / settings.b))
    else:
        print('\nThe solution is:\n' + reduced_fraction(res, settings.b))


def negative_delta_solving():
    res = square_root(settings.delta * -1)
    if res:
        root = str(res)
    else:
        root = '√' + str(settings.delta * -1)

    length = len(str(settings.b * -1 / (2 * settings.a)))
    if settings.b == 0:
        b_quotient = ''
    elif length <= 4 or (length <= 5 and settings.b * -1 / (2 * settings.a) < 0):
        b_quotient = str(settings.b * -1 / (2 * settings.a))
    else:
        b_quotient = reduced_fraction(settings.b * -1, 2 * settings.a)

    print('\nThe two solutions are:\n')

    display.negative_delta_solution(True, root, b_quotient, res)
    display.negative_delta_solution(False, root, b_quotient, res)


def positive_delta_solving():
    res = square_root(settings.delta)
    if res:
        root = str(res)
    else:
        root = '√' + str(settings.delta)

    length = len(str(settings.b * -1 / (2 * settings.a)))

    if settings.b == 0:
        b_quotient = ''
    elif length <= 4 or (length <= 5 and settings.b * -1 / (2 * settings.a) < 0):
        b_quotient = str(settings.b * -1 / (2 * settings.a))
    else:
        b_quotient = reduced_fraction(settings.b * -1, 2 * settings.a)

    print('\nThe two solutions are:\n')

    display.positive_delta_solution(True, root, b_quotient, res)
    display.positive_delta_solution(False, root, b_quotient, res)


def second_degree_solving():
    settings.delta = settings.b * settings.b - (4 * settings.a * settings.c)
    display.delta()

    if settings.delta < 0:
        negative_delta_solving()
    elif settings.delta == 0:
        length = len(str(settings.b * -1 / 2 * settings.a))
        print('\nThe solution is:\n')
        print('x = -b / 2a')
        print('  =', str(settings.b * -1), '/', str(2 * settings.a))
        if length <= 4 or (length <= 5 and settings.b * -1 / (2 * settings.a) < 0):
            print('  =', str(settings.b * -1 / (2 * settings.a)))
        else:
            print('  =', reduced_fraction(settings.b * -1, 2 * settings.a))
    else:
        positive_delta_solving()


def start():
    if settings.a:
        second_degree_solving()
    else:
        normal_solving()
