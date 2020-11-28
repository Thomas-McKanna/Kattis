n = int(input())
while n != 0:
    stan = 0
    ollie = 0
    points = []
    for i in range(n):
        if i == n // 2:
            cross_x, cross_y = [int(i) for i in input().split()]
        else:
            x, y = [int(i) for i in input().split()]
            points.append((x, y))
    for point in points:
        x, y = point
        # top right
        if x > cross_x and y > cross_y:
            stan += 1
        # bottom left
        elif x < cross_x and y < cross_y:
            stan += 1
        # top left
        elif x < cross_x and y > cross_y:
            ollie += 1
        # bottom right
        elif x > cross_x and y < cross_y:
            ollie += 1
    print(stan, ollie)
    n = int(input())
