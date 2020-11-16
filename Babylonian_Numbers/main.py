N = int(input())
for _ in range(N):
    nums = input().split(',')
    answer = 0
    i = 0
    for num in nums[::-1]:
        if num != '':
            answer += 60**i * int(num)
        i += 1
    print(answer)
