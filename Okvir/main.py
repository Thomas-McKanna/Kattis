M, N = [int(i) for i in input().split()]
U, L, R, D = [int(i) for i in input().split()]
board = [['!' for _ in range(N + L + R)] for _ in range(M + U + D)]

# read in letters
for i in range(M):
    line = input()
    for j in range(len(line)):
        board[U + i][L + j] = line[j]

start_hash = True
for i in range(len(board)):
    hash_next = start_hash
    for j in range(len(board[i])):
        if board[i][j] == '!':
            if hash_next: board[i][j] = '#'
            else: board[i][j] = '.'
        hash_next = not hash_next
    start_hash = not start_hash

for row in board:
    print(''.join(row))
