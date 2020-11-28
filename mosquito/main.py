try:
    while True:
        M, P, L, E, R, S, N = [int(i) for i in input().split()]
        for _ in range(N):
            new_L = M * E
            new_P = L // R
            new_M = P // S
            L = new_L
            P = new_P
            M = new_M
        print(M)
except:
    pass
