a, b, c, n = [int(i) for i in input().split()]
a -= 1
b -= 1
c -= 1
n -= 3
if a >= 0 and b >= 0 and c >= 0 and n >= 0 and (a + b + c >= n):
    print("YES")
else:
    print("NO")
