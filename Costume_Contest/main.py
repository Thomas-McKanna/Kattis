N = int(input())
counts = {}
for _ in range(N):
    name = input()
    if name in counts:
        counts[name] += 1
    else:
        counts[name] = 1
min_count = min(counts.values())
answer = []
for name, count in counts.items():
    if count == min_count:
        answer.append(name)
answer = sorted(answer)
for name in answer:
    print(name)
