try:
    while True:
        nums = [int(i) for i in input().split()]
        for j in range(len(nums)):
            current = j
            others = [nums[i] for i in range(len(nums)) if i != current]
            if sum(others) == nums[current]:
                print(nums[current])
                break
except:
    pass
