from itertools import product

class Possibility:
    def __init__(self, v, c):
        self.val = v
        self.combo = c

combos = product(['+', '-', '*', '//'], repeat=3)

possibilities = {} 

for c in combos:
    val = eval('4 {} 4 {} 4 {} 4'
        .format( c[0], c[1], c[2]))
    possibilities[val] = c

n = int(input())

for _ in range(n):
    m = int(input())
    if m in possibilities.keys():
        combo = possibilities[m]
        for op in combo:
            if op == '//':
                op = '/'
            print('4 {} '.format(op), end='')
        print('4 = {}'.format(m))
    else:
        print('no solution')
