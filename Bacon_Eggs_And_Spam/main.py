n = int(input())
while n != 0:
    orders = {}
    for _ in range(n):
        line = input().split()
        name = line[0]
        items = line[1:]
        for item in items:
            if item not in orders:
                orders[item] = [name]
            else:
                orders[item].append(name)
    for item in sorted(orders.keys()):
        print(f'{item} {" ".join(sorted(orders[item]))}')
    print('')
    n = int(input())
