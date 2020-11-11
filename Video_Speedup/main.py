n, p, k = [int(i) for i in input().split()]
t = [int(i) for i in input().split()]
last = 0
speedup = 0
answer = 0.0
for i in t:
    interval_length = i - last
    answer += interval_length * ((100 + speedup)/100)
    speedup += p
    last = i
answer += (k - last) * ((100 + speedup)/100)
print(answer)
