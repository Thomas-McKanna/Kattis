from itertools import combinations

def is_same_subset(s1, s2):
    for i in s1:
        if i not in s2:
            return False
    return True


T = int(input())
for i in range(T):
    print(f'Case #{i + 1}:')
    s = [int(i) for i in input().split()][1:]
    subsets = []
    for i in range(2, 20):
        for c in combinations(s, i):
            subsets.append(c)
    found_answer = False
    for i in range(len(subsets)):
        if found_answer: break
        for j in range(len(subsets)):
            if i != j and sum(subsets[i]) == sum(subsets[j]):
                found_answer = True
                print(' '.join(str(i) for i in subsets[i]))
                print(' '.join(str(i) for i in subsets[j]))
                break   
    if not found_answer:
        print("Impossible")
