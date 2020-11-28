T = int(input())
for _ in range(T):
    n1 = int(input())
    p1 = [int(i) for i in input().split()]
    n2 = int(input())
    p2 = [int(i) for i in input().split()]
    answer = [0 for _ in range(n1 + n2 + 1)]
    for i in range(len(p1)):
        for j in range(len(p2)):
            answer[i + j] += p1[i] * p2[j]
    print(len(answer) - 1)
    print(' '.join([str(i) for i in answer]))
