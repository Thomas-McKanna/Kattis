x_dirs = [1, 0, -1, 0]
y_dirs = [0, -1, 0, 1]

def dfs(x, y, map):
    map[x][y] = 'X'
    for i in range(4):
        new_x = x + x_dirs[i]
        new_y = y + y_dirs[i]
        if 0 <= new_x < r and 0 <= new_y < c and (map[new_x][new_y] == 'L' or map[new_x][new_y] == 'C'):
            dfs(new_x, new_y, map)

r, c = [int(i) for i in input().split()]
map = []
for _ in range(r):
    map.append([c for c in input()])

count = 0
for i in range(r):
    for j in range(c):
        if map[i][j] == 'L':
            count += 1
            dfs(i, j, map)
print(count)
