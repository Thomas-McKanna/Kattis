r, c = [int(i) for i in input().split()]
while r != 0 or c != 0:
    lines = []
    for _ in range(r):
        lines.append(input())
    rotated = ['' for _ in range(c)]
    for i in range(r):
        for j in range(c):
            rotated[j] += lines[i][j]
    rotated = sorted(rotated, key=lambda s: s.lower())
    answer = ['' for _ in range(r)]
    for i in range(c):
        for j in range(r):
            answer[j] += rotated[i][j]
    for i in range(r):
        print(answer[i])
    print()
    r, c = [int(i) for i in input().split()]
