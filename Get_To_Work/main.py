C = int(input())
for case in range(C):
    N, T = [int(i) for i in input().split()]
    drivers = [[] for _ in range(N)]
    E = int(input())
    for _ in range(E):
        H, P = [int(i) for i in input().split()]
        drivers[H - 1].append(P)
    drivers = [sorted(i, reverse=True) for i in drivers]
    answer = [0 for _ in range(N)]
    all_employees_can_travel = True
    for i in range(N):
        if i != T - 1:
            while len(drivers[i]):
                if drivers[i][0] == 0:
                    all_employees_can_travel = False
                    break
                elif drivers[i][0] == 1:
                    drivers[i] = drivers[i][1:]
                else:
                    drivers[i] = drivers[i][1:-drivers[i][0] + 1]
                answer[i] += 1
    if all_employees_can_travel:
        print(f'Case #{case + 1}: {" ".join([str(i) for i in answer])}')
    else:
        print(f'Case #{case + 1}: IMPOSSIBLE')
