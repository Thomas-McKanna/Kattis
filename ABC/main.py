nums = [int(i) for i in input().split()]
nums = sorted(nums)
order = input()
if order == 'ABC':
    print(nums[0], nums[1], nums[2])
elif order == 'ACB':
    print(nums[0], nums[2], nums[1])
elif order == 'BAC':
    print(nums[1], nums[0], nums[2])
elif order == 'BCA':
    print(nums[1], nums[2], nums[0])
elif order == 'CAB':
    print(nums[2], nums[0], nums[1])
else:
    print(nums[2], nums[1], nums[0])
