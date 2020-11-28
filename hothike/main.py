n = int(input())
t = [int(i) for i in input().split()]
best_t = 9999
best_d = 0
i = len(t) - 2
while i > 0:
    if max(t[i - 1], t[i + 1]) <= best_t:
        best_d = i
        best_t = max(t[i - 1], t[i + 1])
    i -= 1
print(best_d, best_t)
