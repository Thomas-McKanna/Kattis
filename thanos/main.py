T = int(input())
for _ in range(T):
    P, R, F = [int(i) for i in input().split()]
    count = 0
    while P <= F:
        P = P * R
        count += 1
    print(count)
