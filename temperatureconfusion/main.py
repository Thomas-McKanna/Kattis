def gcd(a, b):
    if a == 0:
        return b
    else:
        return gcd(b % a, a)

a, b = [int(i) for i in input().split('/')]
c = (a - (32 * b)) * 5
d = 9 * b
divisor = gcd(c, d)
e = c // divisor
f = d // divisor
if (e < 0 and f < 0) or f < 0:
    e = -e
    f = -f
print(f'{e}/{f}')
