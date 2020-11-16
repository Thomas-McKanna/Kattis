X = int(input())
L = input()
M = 0
W = 0
while len(L):
    if len(L) >= 2:
        if M > W and L[1] == 'W':
            W += 1
            L = L[0] + L[2:]
        elif W > M and L[1] == 'M':
            M += 1
            L = L[0] + L[2:]
        elif L[0] == 'M' and abs((M + 1) - W) <= X:
            M += 1
            L = L[1:]
        elif L[1] == 'M' and abs((M + 1) - W) <= X:
            M += 1
            L = L[0] + L[2:]
        elif L[0] == 'W' and abs(M - (W + 1)) <= X:
            W += 1
            L = L[1:]
        elif L[1] == 'W' and abs(M - (W + 1)) <= X:
            W += 1
            L = L[0] + L[2:]
        else:
            L = ''
    else:
        if L[0] == 'M' and abs((M + 1) - W) <= X:
            M += 1
            L = L[1:]
        elif L[0] == 'W' and abs(M - (W + 1)) <= X:
            W += 1
            L = L[1:]
        else:
            L = ''
print(M + W)
