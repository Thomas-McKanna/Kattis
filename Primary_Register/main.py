capacity = [2, 3, 5, 7, 11, 13, 17, 19]
v = [int(i) for i in input().split()]
N = 0
finished = False
while True:
    if finished:
        print(N - 1)
        break
    v[0] += 1
    N += 1
    if v[0] == capacity[0]:
        for j in range(len(v)):
            if v[j] == capacity[j]:
                if j == len(v) - 1:
                    finished = True
                    break
                v[j] = 0
                v[j + 1] += 1
            else: break
