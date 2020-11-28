_ = input()
nums = [int(i) for i in input().split()]
answer = []
for num in nums:
    for i in range(2**8):
        if i ^ (i << 1) % 2**8 == num:
            answer.append(i)
print(' '.join(str(i) for i in answer))
