def get_index(target, nums):
    for i in range(len(nums)):
        if nums[i] == target:
            return i
    return -1

input()
nums = [int(i) for i in input().split()]
counts = {}
for n in nums:
    if n in counts:
        counts[n] += 1
    else:
        counts[n] = 1
items = []
for n, count in counts.items():
    items.append((-count, get_index(n, nums), n))
items = sorted(items)
answer = []
for item in items:
    count, _, num = item
    for i in range(-count):
        answer.append(str(num))
print(' '.join(answer))
