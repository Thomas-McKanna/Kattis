n, m = [int(i) for i in input().split()]
d = {}
for _ in range(n):
    left, right = [i.strip() for i in input().split('->')]
    d[left] = right
S = input()
for _ in range(m):
    new_S = ''
    for c in S:
        if c in d:
            new_S += d[c]
        else:
            new_S += c
    S = new_S
print(S)
