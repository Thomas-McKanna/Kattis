K = int(input())
for i in range(21):
    if 2**i >= K:
        break
j = 0
while K != 0:
    if K & 1:
        break
    K = K >> 1
    j += 1
print(2**i, i - j)
