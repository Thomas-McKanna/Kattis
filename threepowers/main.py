S = [str(3**i) for i in range(64)]
n = int(input())
while n != 0:
    n = n - 1
    answer = []
    i = 0
    while n != 0:
        if n & 1:
            answer.append(S[i])
        n = n >> 1
        i += 1
    print('{ ' + ', '.join(answer) + ' }')
    n = int(input())
