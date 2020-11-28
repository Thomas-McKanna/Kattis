lookup = {}
line = input()
while line != '0':
    if '=' in line:
        left, right = [i.strip() for i in line.split('=')]
        lookup[left] = right
    else:
        expression = []
        tokens = [i.strip() for i in line.split('+')]
        unresolved_symbols = []
        running_sum = 0
        for t in tokens:
            if t in lookup:
                running_sum += int(lookup[t])
            elif t.isnumeric():
                running_sum += int(t)
            else:
                unresolved_symbols.append(t)
        if running_sum != 0 and not len(unresolved_symbols):
            print(running_sum)
        elif running_sum != 0 and len(unresolved_symbols):
            unresolved_symbols = [str(running_sum)] + unresolved_symbols
            print(' + '.join(unresolved_symbols))
        else:
            print(' + '.join(unresolved_symbols))
    line = input()
