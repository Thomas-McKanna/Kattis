N, b = [int(i) for i in input().split()]
if b == 0 and N == 1:
    print("yes")
else:
    print("yes") if N <= b else print("no")
