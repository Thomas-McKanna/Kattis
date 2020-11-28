parent = [-1 for _ in range(101)]
k = int(input())
line = [int(i) for i in input().split()]
while line[0] != -1:
    for i in line[1:]:
        parent[i] = line[0]
    line = [int(i) for i in input().split()]
answer = [k]
while parent[k] != -1:
    answer.append(parent[k])
    k = parent[k]
print(' '.join([str(i) for i in answer]))
