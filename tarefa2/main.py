import math

# funcao a ser integrada, de 0 a 10
def f(x):
    return math.log(((x**2) * math.sin(x))**2)


def integral(f, a, b, n_splits, poly):
    area = 0
    h = (b - a)/n_splits
    i = a

    while i < b:
        area += poly(f, i, h)
        i += h
    
    return area


def fechada(f, a, h):
    k = h/4
    return k*((14*f(a) + 64*f(a+k) + 24*f(a+2*k) + 64*f(a+3*k) + 14*f(a+4*k))/45)


def aberta(f, a, h):
    k = h/6
    return k*((33*f(a+k) - 42*f(a+2*k) + 78*f(a+3*k) - 42*f(a+4*k) + 33*f(a+5*k))/10)


def test_integral(f, a, b, poly, thr=1e-6):
    err = 1
    int_0 = 0
    n_splits = 2
    while err > thr:
        int_1 = integral(f, a, b, n_splits, poly)
        err = abs((int_1 - int_0)/int_1)
        print(f'n_splits: {n_splits:2d} | int: {int_1:.7f} | err: {err:.7f}')
        int_0 = int_1
        n_splits *= 2


print('FECHADA')
test_integral(f, 1, 7.3, fechada)

print('\nABERTA')
test_integral(f, 1, 7.3, aberta)