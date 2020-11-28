T = int(input())
for _ in range(T):
    n = int(input())
    points = 0
    for _ in range(n):
        x, y = [int(i) for i in input().split()]
        r = (x**2 + y**2)**(1/2)
        if r > 200: continue
        for p in range(10, 0, -1):
            if r <= 20 * (11 - p):
                points += p
                break
    print(points)
