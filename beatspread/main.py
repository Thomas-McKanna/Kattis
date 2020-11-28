n = int(input())
for _ in range(n):
    s, d = [int(i) for i in input().split()]
    found_valid = False
    for i in range(1001):
        if found_valid: break
        for j in range(1001):
            if i + j == s and abs(i - j) == d:
                print(f'{max(i, j)} {min(i, j)}')
                found_valid = True
                break
    if not found_valid:
        print('impossible')
