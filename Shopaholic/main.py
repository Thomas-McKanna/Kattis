n = int(input())
p = sorted([int(i) for i in input().split()], reverse=True)
discount = 0
for i in range(2, n, 3):
    discount += p[i]
print(discount)
