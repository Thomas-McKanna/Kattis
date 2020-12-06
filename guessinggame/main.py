n = int(input())
while n != 0:
    hi = 10
    lo = 1
    response = input()
    while response != 'right on':
        if response == 'too high':
            hi = min(n - 1, hi)
        elif response == 'too low':
            lo = max(n + 1, lo)
        n = int(input())
        response = input()
    if lo <= n <= hi:
        print('Stan may be honest')
    else:
        print('Stan is dishonest')
    n = int(input())
