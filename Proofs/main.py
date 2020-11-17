from sys import exit

n = int(input())
truths = set()
for i in range(n):
    assumptions, conclusions = input().split('->')
    assumptions = assumptions.strip()
    for a in assumptions.split():
        if a not in truths:
            print(i + 1)
            exit(0)
    conclusions = conclusions.strip()
    for c in conclusions.split():
        truths.add(c)
print('correct')
