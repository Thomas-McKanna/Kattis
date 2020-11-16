from sys import exit

P, S = input().split()
for c in S:
    if c in P:
        if c == P[0]:
            P = P[1:]
            if not len(P):
                print('PASS')
                exit(0)
        else:
            print('FAIL')
            exit(0)
print('FAIL')
