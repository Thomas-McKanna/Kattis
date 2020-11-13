N = int(input())
d = []
for _ in range(N):
    d.append(int(input()))
d = d + [d[0], d[1]]
best = 999999
for i in range(N):
    if d[i] + d[i + 2] < best:
        best = d[i] + d[i + 2]
print(best)
