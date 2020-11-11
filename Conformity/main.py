n = int(input())
counts = {}
for _ in range(n):
    nums = [int(i) for i in input().split()]
    nums = sorted(nums)
    nums = ''.join([str(i) for i in nums])
    if nums not in counts:
        counts[nums] = 1
    else:
        counts[nums] = counts[nums] + 1
most_popular_count = 0
for key, value in counts.items():
    if value > most_popular_count:
        most_popular_count = value
answer = 0
for key, value in counts.items():
    if value == most_popular_count:
        answer += value
print(answer)
