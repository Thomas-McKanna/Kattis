def get_dist(x1, y1, x2, y2):
    x_diff = x1 - x2
    y_diff = y1 - y2
    return (x_diff**2 + y_diff**2)**(1/2)

N = int(input())
for _ in range(N):
    found_viable_option = False
    S, H = [int(i) for i in input().split()]
    hatches = []
    for _ in range(H):
        hatches.append([int(i) for i in input().split()])
    for x in range(S + 1):
        for y in range(S + 1):
            # get max leesh distance needed for this coord
            max_dist = 0
            for h1, h2 in hatches:
                if x == h1 and y == h2: 
                    max_dist = 99999
                    break
                dist = get_dist(x, y, h1, h2)
                if dist > max_dist:
                    max_dist = dist
            if x - max_dist >= 0 and x + max_dist <= S and y - max_dist >= 0 and y + max_dist <= S:
                found_viable_option = True
                break
        if found_viable_option:
            break
    print(x, y) if found_viable_option else print("poodle")
