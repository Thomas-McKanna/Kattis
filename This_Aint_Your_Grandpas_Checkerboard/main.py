n = int(input())
board = []
for _ in range(n):
    board.append(input())

valid = True

# check rows
for i in range(n):
    black_count = 0
    white_count = 0
    for j in range(n):
        if board[i][j] == 'W':
            white_count += 1
        else:
            black_count += 1
    if white_count != black_count:
        valid = False
        break

# check columns
for i in range(n):
    black_count = 0
    white_count = 0
    for j in range(n):
        if board[j][i] == 'W':
            white_count += 1
        else:
            black_count += 1
    if white_count != black_count:
        valid = False
        break

# check for consequtive in rows
for row in board:
    if 'WWW' in row or 'BBB' in row:
        valid = False
        break

copy_board = []
for i in range(n):
    row = []
    for j in range(n):
        row.append(board[j][i])
    copy_board.append(''.join(row))

# check for consequtive in columns
for row in copy_board:
    if 'WWW' in row or 'BBB' in row:
        valid = False
        break

print(1) if valid else print(0)
