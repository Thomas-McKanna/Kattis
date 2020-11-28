from sys import exit

x_dir = [1, 0, -1, 0]
y_dir = [0, 1, 0, -1]
index = {
    'N': 2,
    'S': 0,
    'W': 3,
    'E': 1
}

R, C = [int(i) for i in input().split()]
visited = set()
map = []
for _ in range(R):
    map.append(input())
x = 0
y = 0
count = 0
while True:
    if map[x][y] == 'T':
        print(count)
        exit(0)
    new_x = x + x_dir[index[map[x][y]]]
    new_y = y + y_dir[index[map[x][y]]]
    if 0 <= new_x < R and 0 <= new_y < C:
        if 1000 * new_x + new_y in visited:
            print('Lost')
            exit(0)
        else:
            visited.add(1000 * new_x + new_y)
            x = new_x
            y = new_y
            count += 1
    else:
        print('Out')
        exit(0)
