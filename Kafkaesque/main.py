K = int(input())
nums = []

for _ in range(K):
    nums.append(int(input()))

signed = [False for _ in range(K)]

passes = 0
while not all(signed):
    passes += 1
    last = 0
    for i in range(K):
        if not signed[i]:
            if last < nums[i]:
                last = nums[i]
                signed[i] = True
            else:
                break

print(passes)        
