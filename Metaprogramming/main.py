dict = {}
try:
    while True:
        line = input().split()
        if line[0] == 'define':
            dict[line[2]] = int(line[1])
        else:
            s1 = line[1]
            s2 = line[3]
            if s1 not in dict or s2 not in dict:
                print('undefined')
            else:
                i1 = dict[s1]
                i2 = dict[s2]
                if line[2] == '<':
                    print('true') if i1 < i2 else print('false')
                elif line[2] == '>':
                    print('true') if i1 > i2 else print('false')
                else:
                    print('true') if i1 == i2 else print('false')
except:
    pass
