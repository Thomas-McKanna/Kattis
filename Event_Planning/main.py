N, B, H, W = [int(i) for i in input().split()]
best = 99999999
for _ in range(H):
    p = int(input())
    max_beds = max([int(i) for i in input().split()])
    if max_beds >= N and p * N <= B:
        best = min(best, p * N)
print(best) if best != 99999999 else print("stay home")
