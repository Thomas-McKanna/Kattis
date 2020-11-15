line = input().split()
H = int(line[0])
if len(line) == 1: moves = ''
else: moves = line[1]
answer = 0
for move in moves:
    if move == 'L': answer = 2 * answer + 1
    else: answer = 2 * answer + 2
print(2**(H + 1) - 1 - answer)
