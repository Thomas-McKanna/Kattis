N = int(input())
villagers = [set() for _ in range(N + 1)]
E = int(input())
for i in range(E):
    line = [int(i) for i in input().split()]
    K = line[0]
    present = sorted(line[1:])
    if present[0] == 1:
        for v in present:
            villagers[v].add(i)
    else:
        all_songs_known = set()
        for v1 in present:
            for v2 in present:
                villagers[v2] = villagers[v2].union(villagers[v1])
            
total_songs = len(villagers[1])
for i in range(1, N + 1):
    if len(villagers[i]) == total_songs:
        print(i)
