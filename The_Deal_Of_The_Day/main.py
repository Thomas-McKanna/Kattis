from itertools import combinations

def is_sorted(L):
    for i in range(1, len(L)):
        if L[i - 1] > L[i]:
            return False
    return True

n = [int(i) for i in input().split()]
i = [i for i in range(10)]
K = int(input())
answer = 0
for comb in combinations(i, K):
    if is_sorted(comb) and not len([n[j] for j in comb if n[j] == 0]):
        product = 1
        for j in comb:
            product *= n[j]
        answer += product
print(answer)
