def get_24_hr_format(t):
    t = t.split()
    h, m = [int(i) for i in t[0].split(':')]
    if h == 12:
        h = 0
    result = 60 * h + m
    if t[1] == 'p.m.':
        result += 60 * 12
    return result

n = int(input())
while n != 0:
    times = []
    for _ in range(n):
        raw = input()
        times.append((get_24_hr_format(raw), raw))
    times = sorted(times)
    for t in times:
        print(t[1])
    print()
    n = int(input())
