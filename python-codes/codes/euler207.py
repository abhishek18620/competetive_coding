from fractions import Fraction
from math import log

calc_k = lambda x: x * (x - 1)

cant_perf = 1
cant_tot = 1
limit = Fraction(1, 12345)

if __name__ == '__main__':
    i = 3
    while Fraction(cant_perf, cant_tot) >= limit:
        log_2 = int(log(i,2))
        if 2 ** log_2 == i:
            cant_perf += 1
        cant_tot += 1
        i += 1
    i -= 1
    print(i)
    print("The result is:", calc_k(i))
