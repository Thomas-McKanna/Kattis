def get_dist(x1, y1, x2, y2):
    x_diff = x1 - x2
    y_diff = y1 - y2
    return (x_diff**2 + y_diff**2)**(1/2)

gx, gy, dx, dy = [float(i) for i in input().split()]
try:
    while True:
        x, y = [float(i) for i in input().split()]
        if get_dist(gx, gy, x, y) * 2 <= get_dist(dx, dy, x, y):
            print(f'The gopher can escape through the hole at ({x},{y}).')
            break
except:
    print('The gopher cannot escape.')
