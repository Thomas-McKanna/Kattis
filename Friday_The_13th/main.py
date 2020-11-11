T = int(input())
week = ['S', 'M', 'T', 'W', 'Th', 'F', 'Sa']
for _ in range(T):
    D, M = [int(i) for i in input().split()]
    d = [int(i) for i in input().split()]
    answer = 0
    current = 0
    while current + 1 != D:
        day_name = week[current % 7]
        day_number = current + 1
        for i in range(M):
            if day_number > d[i]:
                day_number -= d[i]
            else:
                break
        if day_number == 13 and day_name == 'F':
            answer += 1
        current += 1
    print(answer)
