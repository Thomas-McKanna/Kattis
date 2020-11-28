N, K = [int(i) for i in input().split()]
health_map = {}
health = []
attack_map = {}
attack = []
defense_map = {}
defense = []
for i in range(N):
    A, D, H = [int(i) for i in input().split()]
    attack_map[A] = i
    attack.append(A)
    defense_map[D] = i
    defense.append(D)
    health_map[H] = i
    health.append(H)
chosen = set([attack_map[i] for i in sorted(attack, reverse=True)[:K]])
chosen = chosen.union(set([defense_map[i] for i in sorted(defense, reverse=True)[:K]]))
chosen = chosen.union(set([health_map[i] for i in sorted(health, reverse=True)[:K]]))
print(len(chosen))
