nums = sorted([int(i) for i in input().split()])
differences = set()
for i in range(1, len(nums)):
    differences.add(nums[i] - nums[i - 1])

if len(differences) == 1:
    print(nums[-1] + differences.pop())
else:
    diff = max(differences) // 2
    i = nums[0]
    while i != nums[-1]:
        if i + diff not in nums:
            print(i + diff)
        i += diff
