a, b, c, d = map(int, input().split())
times = input().split()

for t in times:
    t = int(t)
    # dog 1
    temp = t % (a + b)
    if temp > 0 and temp <= a:
        dog1 = True
    else:
        dog1 = False

    # dog 2
    temp = t % (c + d)
    if temp > 0 and temp <= c:
        dog2 = True
    else:
        dog2 = False

    if dog1 and dog2:
        print('both')
    elif dog1 or dog2:
        print('one')
    else:
        print('none')
        
