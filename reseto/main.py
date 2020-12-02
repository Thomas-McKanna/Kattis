N, K = [int(i) for i in input().split()]
nums = [True for _ in range(N + 1)]
count = 0
for i in range(2, N + 1):
    if nums[i]:
        j = 1
        while i * j <= N:
            if nums[i * j]:
                nums[i * j] = False
                count += 1
                if count == K:
                    print(i * j)
                
            j += 1
