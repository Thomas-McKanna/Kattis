N = int(input())
a = [int(i) for i in input().split()]
g = [a[0]]
for i in range(1, len(a)):
    if a[i] > g[-1]:
        g.append(a[i])
print(len(g))
print(' '.join([str(i) for i in g]))
