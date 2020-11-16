def get_distance(x1, y1, x2, y2):
    x_diff = x1 - x2
    y_diff = y1 - y2
    return (x_diff**2 + y_diff**2)**(1/2)

d, N = input().split()
while d != '0.0' or N != '0':
    d = float(d)
    N = int(N)
    b = []
    for _ in range(N):
        x, y = [float(i) for i in input().split()]
        b.append((x, y))
    num_sour = 0
    for i in range(N):
        for j in range(N):
            if i != j:
                if get_distance(b[i][0], b[i][1], b[j][0], b[j][1]) <= d:
                    num_sour += 1
                    break
    print(f'{num_sour} sour, {N - num_sour} sweet')
    d, N = input().split()
