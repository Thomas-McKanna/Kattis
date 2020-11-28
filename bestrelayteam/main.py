from itertools import permutations

a = []
b = []
n = int(input())
for _ in range(n):
    name, ai, bi = input().split()
    ai = float(ai)
    bi = float(bi)
    a.append((ai, name))
    b.append((bi, name))
    
a = sorted(a)[:8]
b = sorted(b)[:8]

best_time = 99999
best_roster = []
for time_a, p1 in a:
    roster = [(time_a, p1)]
    for time_b, p2 in b:
        if p1 != p2:
            roster.append((time_b, p2))
        if len(roster) == 4:
            break
    if sum(i[0] for i in roster) < best_time:
        best_time = sum(i[0] for i in roster)
        best_roster = (i[1] for i in roster)

print(best_time)
for p in best_roster:
    print(p)
