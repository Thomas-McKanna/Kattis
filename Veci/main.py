from itertools import permutations

X = input()
ans = 9999999
for i in permutations(X):
    num = int(''.join(i))
    if num > int(X) and num < ans:
        ans = num
print(ans) if ans != 9999999 else print(0)
