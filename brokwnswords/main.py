N = int(input())
TB = 0
LR = 0
for _ in range(N):
    line = input()
    if line[0] == '0':
        TB += 1
    if line[1] == '0':
        TB += 1
    if line[2] == '0':
        LR += 1
    if line[3] == '0':
        LR += 1
count = 0
while TB >= 2 and LR >= 2:
    count += 1
    TB -= 2
    LR -= 2
print(count, TB, LR)
