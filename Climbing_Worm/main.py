a, b, h = [int(i) for i in input().split()]
current = 0
answer = 0
while current < h:
    answer += 1
    current += a
    if current >= h:
        break
    current -= b
print(answer)
