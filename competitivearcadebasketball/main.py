n, p, m = [int(i) for i in input().split()]
players = {}
for _ in range(n):
    players[input()] = 0
somebody_one = False
for _ in range(m):
    name, points = input().split()
    points = int(points)
    players[name] += points
    if players[name] >= p:
        print(f'{name} wins!')
        somebody_one = True
        players[name] = -99999999
if not somebody_one:
    print('No winner!')
