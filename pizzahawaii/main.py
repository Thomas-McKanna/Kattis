from copy import copy
t = int(input())
for _ in range(t):
    n = int(input())
    pizzas = [[set(), set()] for _ in range(n)]
    for i in range(n):
        _ = input()
        foreign = input().split()[1:]
        native = input().split()[1:]
        pizzas[i][0] = set(foreign)
        pizzas[i][1] = set(native)
    answer = set()
    for fset1, nset1 in pizzas:
        for foreign in fset1:
            for native in nset1:
                add_to_answer = True
                for fset2, nset2 in pizzas:
                    if foreign in fset2 and native not in nset2:
                        add_to_answer = False
                        break
                if add_to_answer:
                    answer.add(f'({foreign}, {native})')
    print('\n'.join(sorted(list(answer))))
    print()
