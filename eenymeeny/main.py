p = len(input().split())
n = int(input())
kids = []
for _ in range(n):
    kids.append(input())
team1 = []
team2 = []
i = n - 1
choosing_team1 = True
while len(team1) + len(team2) != n:
    current = p
    while current != 0:
        if kids[(i + 1) % n] != 'chosen':
            current -= 1
        i = (i + 1) % n
    if choosing_team1:
        team1.append(kids[i])
    else:
        team2.append(kids[i])
    kids[i] = 'chosen'
    choosing_team1 = not choosing_team1
print(len(team1))
for k in team1:
    print(k)
print(len(team2))
for k in team2:
    print(k)
