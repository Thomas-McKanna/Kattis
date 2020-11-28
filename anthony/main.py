from math import pi
A, N = [float(i) for i in input().split()]
r1 = N / (2 * pi)
r2 = (A / pi)**(1/2)
if r1 >= r2:
    print('Diablo is happy!')
else:
    print('Need more materials!')
