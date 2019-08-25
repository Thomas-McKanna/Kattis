
from sys import maxsize

NO_ROUTE = maxsize

# Get input
n, m = map(int, input().split())
grid = []
for i in range(n):
    i = list(map(int, [ch for ch in input()]))
    grid.append(i)

solved_grid = [[NO_ROUTE for j in range(m)] for i in range(n)]

# Start at beginning: zero since we are already there
solved_grid[0][0] = 0

# Queue of spots to inspect (start at end)
queue = [(0, 0)]

while len(queue):
    x, y = queue.pop()
    jump_distance = grid[x][y]
    if x - jump_distance >= 0:
        if solved_grid[x - jump_distance][y] > solved_grid[x][y] + 1:
            solved_grid[x - jump_distance][y] = solved_grid[x][y] + 1
            queue.append((x - jump_distance, y))
    if x + jump_distance < n:
        if solved_grid[x + jump_distance][y] > solved_grid[x][y] + 1:
            solved_grid[x + jump_distance][y] = solved_grid[x][y] + 1
            queue.append((x + jump_distance, y))
    if y - jump_distance >= 0:
        if solved_grid[x][y - jump_distance] > solved_grid[x][y] + 1:
            solved_grid[x][y - jump_distance] = solved_grid[x][y] + 1
            queue.append((x, y - jump_distance))
    if y + jump_distance < m:
        if solved_grid[x][y + jump_distance] > solved_grid[x][y] + 1:
            solved_grid[x][y + jump_distance] = solved_grid[x][y] + 1
            queue.append((x, y + jump_distance))

if solved_grid[n-1][m-1] == NO_ROUTE:
    print(-1)
else:
    print(solved_grid[n-1][m-1])
