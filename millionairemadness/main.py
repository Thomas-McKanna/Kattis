M, N = [int(i) for i in input().split()]
map = []

x_dir = [1, 0, -1, 0]
y_dir = [0, 1, 0, -1]

def backtrack(ladder, x, y):
    if x == M - 1 and y == N - 1:
        return True
    success = False
    original = map[x][y]
    map[x][y] = -1
    for i in range(4):
        new_x = x + x_dir[i]
        new_y = y + y_dir[i]
        if 0 <= new_x < M and 0 <= new_y < N and map[new_x][new_y] != -1 and original + ladder >= map[new_x][new_y]:
            success = backtrack(ladder, new_x, new_y)
            if success: return True
    map[x][y] = original  
    return False

for i in range(M):
    map.append([int(i) for i in input().split()])
L = 0
while True:
    if backtrack(L, 0, 0):
        print(L)
        break
    L += 1
