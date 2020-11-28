names = []
try:
    while True:
        f, l = input().split()
        names.append((l, f))
except:
    names = sorted(names)
    for last, first in names:
        line = first
        if [f for l, f in names].count(first) > 1:
            line += ' ' + last
        print(line)
