def in_bounds(x1, y1, x2, y2, x3, y3):
    # checks if (x3, y3) is within box (x1, y1), (x2, y2)
    return x1 <= x3 <= x2 and y1 <= y3 <= y2

n = int(input())
while n != 0:
    box_coords = []
    box_sizes = []
    for _ in range(n):
        line = input().split()
        box_coords.append([float(i) for i in line[:4]])
        box_sizes.append(line[4])
    m = int(input())
    peanut_coords = []
    peanut_sizes = []
    for _ in range(m):
        line = input().split()
        peanut_coords.append([float(i) for i in line[:2]])
        peanut_sizes.append(line[2])
    for i in range(m):
        found_spot = False
        for j in range(n):
            if in_bounds(box_coords[j][0], box_coords[j][1], box_coords[j][2], box_coords[j][3], peanut_coords[i][0], peanut_coords[i][1]):
                if peanut_sizes[i] == box_sizes[j]:
                    print(peanut_sizes[i], "correct")
                else:
                    print(peanut_sizes[i], box_sizes[j])
                found_spot = True
                break
        if not found_spot:
            print(peanut_sizes[i], "floor")
    print()
    n = int(input())
