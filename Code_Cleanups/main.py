n = int(input())
days = [int(i) for i in input().split()]
dirty_pushes = 0
dirtiness = 0
answer = 0
for i in range(1, 366):
    if i in days:
        dirty_pushes += 1
    if dirtiness + dirty_pushes >= 20:
        answer += 1
        dirtiness = 0
        dirty_pushes = 0
    else:
        dirtiness += dirty_pushes
if dirtiness != 0:
    answer += 1
print(answer)
