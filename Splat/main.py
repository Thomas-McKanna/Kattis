from math import pi

def get_dist(x1, y1, x2, y2):
    x_diff = x1 - x2
    y_diff = y1 - y2
    return (x_diff**2 + y_diff**2)**(1/2)

c = int(input())
for _ in range(c):
    n = int(input())
    drops = []
    for _ in range(n):
        x, y, v, color = input().split()
        x = float(x)
        y = float(y)
        v = float(v)
        drops.append((x, y, v, color))
    m = int(input())
    for _ in range(m):
        x, y = [float(i) for i in input().split()]
        answer = 'white'
        for drop in drops:
            r = (drop[2]/pi)**(1/2)
            if get_dist(x, y, drop[0], drop[1]) <= r:
                answer = drop[3]
        print(answer)
