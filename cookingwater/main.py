N = int(input())
lbound = 0
rbound = 1000
gunilla_right = True
for _ in range(N):
    a, b = [int(i) for i in input().split()]
    if lbound > b or rbound < a:
        print("edward is right")
        gunilla_right = False
        break
    lbound = max(lbound, a)
    rbound = min(rbound, b)
if gunilla_right:
    print("gunilla has a point")
