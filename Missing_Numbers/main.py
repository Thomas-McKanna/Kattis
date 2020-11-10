n = int(input())
nums = [False for _ in range(201)]
largest = 1
for i in range(n):
    current = int(input())
    nums[current] = True
    if i == n - 1:
        largest = current

all_good = True
for i in range(1, largest + 1):
    if not nums[i]:
        print(i)
        all_good = False

if all_good:
    print("good job")
