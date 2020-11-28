from math import ceil
T = int(input())
for _ in range(T):
    n = int(input())
    counts = []
    count_set = set()
    total = 0
    for i in range(n):
        val = int(input())
        total += val
        count_set.add(val)
        counts.append((val, i + 1))
    counts = sorted(counts, reverse=True)
    if counts[0][0] > total // 2:
        print(f'majority winner {counts[0][1]}')
    elif counts[0][0] != counts[1][0]:
        print(f'minority winner {counts[0][1]}')
    else:
        print('no winner')
