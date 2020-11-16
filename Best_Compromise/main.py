t = int(input())
for _ in range(t):
    n, m = [int(i) for i in input().split()]
    lines = []
    for _ in range(n):
        lines.append(input())
    answer = ''
    for i in range(m):
        zero_count = 0
        one_count = 0
        for line in lines:
            if line[i] == '0':
                zero_count += 1
            else:
                one_count += 1
        if zero_count > one_count:
            answer += '0'
        else:
            answer += '1'
    print(answer)
