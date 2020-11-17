def fact(n):
    if n == 0: return 1
    product = 1
    for i in range(1, n + 1):
        product *= i
    return product

def comb(n, r):
    return fact(n) // (fact(r) * fact(n - r))

N = int(input())
answer = 0
for i in range(2, N + 1):
    answer += comb(N, i)
print(answer)
