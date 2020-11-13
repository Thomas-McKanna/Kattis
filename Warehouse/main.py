T = int(input())
for _ in range(T):
    dict = {}
    N = int(input())
    for _ in range(N):
        name, count = input().split()
        count = int(count)
        if name in dict:
            dict[name] += count
        else:
            dict[name] = count
    answer = [(-count, name) for name, count in dict.items()]
    answer = sorted(answer)
    print(len(dict.keys()))
    for count, name in answer:
        print(name, -count)
