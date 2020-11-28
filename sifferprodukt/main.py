x = int(input())
while x not in range(1, 10):
    product = 1
    while x != 0:
        if x % 10 != 0:
            product *= x % 10
        x //= 10
    x = product
print(x)
