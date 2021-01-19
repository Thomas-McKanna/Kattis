def extended_euclid(a, b):
    if b == 0:
        return (a, 1, 0)
    else:
        d_, x_, y_ = extended_euclid(b, a % b)
        d, x, y = (d_, y_, x_ - (a // b) * y_)
        return (d, x, y)

T = int(input())
for _ in range(T):
    a, n, b, m = [int(i) for i in input().split()]
    _, q, r = extended_euclid(m, n)
    c_1 = m * (q % n)
    c_2 = n * (r % m)
    x = (a * c_1 + b * c_2) % (n * m)
    print(x, n * m)
