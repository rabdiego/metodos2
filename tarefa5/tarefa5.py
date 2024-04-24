import math

def F(x):
    return math.sin(3*x) + math.cos(2*x) + 3

def _gauss_legendre(f, x_i, x_f):
    def x(a):
        return (x_i + x_f)/2 + ((x_f - x_i)/2)*a
    
    a_k = [
        -math.sqrt((3 - 2*math.sqrt(6/5))/7),
        -math.sqrt((3 + 2*math.sqrt(6/5))/7),
        math.sqrt((3 - 2*math.sqrt(6/5))/7),
        math.sqrt((3 + 2*math.sqrt(6/5))/7)
    ]

    w_k = [
        (18 + math.sqrt(30))/36,
        1/2 - math.sqrt(5/6)/6,
        1/2 - math.sqrt(5/6)/6,
        (18 + math.sqrt(30))/36
    ]

    sum = 0
    for i in range(4):
        sum += f(x(a_k[i]))*w_k[i]

    return ((x_f - x_i)/2)*sum


def gauss_legendre(f, x_i, x_f, n_split=1):
    h = (x_f - x_i)/n_split
    sum = 0
    for i in range(n_split):
        sum += _gauss_legendre(f, x_i + i*h, x_i + (i+1)*h)
    return sum


current = gauss_legendre(F, 0, 6, 1)
err = 1
i = 1
print(f' {i:3d} | --------- | {current:2.6f} | {err:1.6f} ')
while err > 1e-6:
    i += 1
    previous = current
    current = gauss_legendre(F, 0, 6, i)
    err = abs((current - previous)/current)
    print(f' {i:3d} | {previous:2.6f} | {current:2.6f} | {err:1.6f} ')
