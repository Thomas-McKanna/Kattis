from math import floor

n = 10000
prime = [True for _ in range(n + 1)]
prime[1] = False
for i in range(2, floor(n*(1/2))):
    if prime[i]:
        j = i**2
        while j <= n:
            prime[j] = False
            j += i

def is_happy(x):
    i = 0
    while i < 10000:
        new_x = 0
        while x != 0:
            new_x += (x % 10)**2
            x = x // 10
        if new_x == 1:
            return True
        x = new_x
        i += 1
    return False

P = int(input())
for _ in range(P):
    case, num = input().split()
    num = int(num)
    if prime[num] and is_happy(num):
        answer = 'YES'
    else:
        answer = 'NO'
    print(f'{case} {num} {answer}')
