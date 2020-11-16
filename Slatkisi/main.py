C, K = [int(i) for i in input().split()]
K = 10**K
remainder = C % K
C = (C // K) * K
if K == 1:
    print(C)
elif remainder >= K // 2:
    print(C + K)
else:
    print(C)
