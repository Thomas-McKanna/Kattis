s = input()
counts = {}
for c in s:
    if c in counts:
        counts[c] += 1
    else:
        counts[c] = 1
answer = 0
while len(counts.keys()) > 2:
    min_count = 9999
    min_k = ''
    for k, v in counts.items():
        if v < min_count:
            min_count = v
            min_k = k
    answer += min_count
    del counts[min_k]
print(answer)
