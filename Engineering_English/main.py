seen = set()
try:
    while True:
        line = input().split()
        for i in range(len(line)):
            if line[i].lower() in seen:
                line[i] = '.'
            else:
                seen.add(line[i].lower())
        print(' '.join(line))
except:
    pass
