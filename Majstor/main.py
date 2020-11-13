def get_score(sven, other):
    if sven== 'S' and other== 'P':
        return 2
    elif sven== 'P' and other== 'R':
        return 2
    elif sven== 'R' and other== 'S':
        return 2
    elif sven== other:
        return 1
    return 0

R = int(input())
sven = input()
N = int(input())
others = []
for _ in range(N):
    others.append(input())
actual = 0
largest_possible = 0

for j in range(len(sven)):
    for i in range(N):
        actual += get_score(sven[j], others[i][j])
    if_R = 0
    for i in range(N):
        if_R += get_score('R', others[i][j])
    if_P = 0
    for i in range(N):
        if_P += get_score('P', others[i][j])
    if_S = 0
    for i in range(N):
        if_S += get_score('S', others[i][j])
    largest_possible += max(if_R, if_P, if_S)
        
print(actual)
print(largest_possible)
