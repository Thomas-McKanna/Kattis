a, b = [int(i) for i in input().split()]
c, d = [int(i) for i in input().split()]
t = int(input())
t -= abs(a - c) + abs(b - d)
print("Y") if t >= 0 and t % 2 == 0 else print("N")
