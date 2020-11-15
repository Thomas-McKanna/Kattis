N = int(input())
for _ in range(N):
    C, D, H, M = input().split()
    D = int(D)
    H = int(H)
    M = int(M)
    if C == 'F':
        M += D
    else:
        M -= D
    while M > 59:
        H = (H + 1) % 24
        M -= 60
    while M < 0:
        H = (H - 1) % 24
        M += 60
    print(H, M)
