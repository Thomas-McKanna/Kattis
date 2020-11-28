n = int(input())
s = sorted(
    list(zip(
        map(int, input().split()), 
        [i for i in range(1, n + 1)]
    )), 
    reverse=True
)

starting_size = s[0][0]
for size in [t[0] for t in s[1:]]:
    starting_size -= size

if starting_size <= 0:
    print(' '.join([str(t[1]) for t in s]))
else:
    print('impossible')
