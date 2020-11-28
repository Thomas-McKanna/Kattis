def get_short_name(s):
    if s == 'thou': return 'th'
    if s == 'inch': return 'in'
    if s == 'foot': return 'ft'
    if s == 'yard': return 'yd'
    if s == 'chain': return 'ch'
    if s == 'furlong': return 'fur'
    if s == 'mile': return 'mi'
    if s == 'league': return 'lea'
    return s

def product(iter):
    p = 1
    for i in iter:
        p *= i
    return p

name = ['th', 'in', 'ft', 'yd', 'ch', 'fur', 'mi', 'lea']
val = [1, 1000, 12, 3, 22, 10, 8, 3]
v, u, _, s = input().split()
v = int(v)
u = get_short_name(u)
s = get_short_name(s)
u = name.index(u)
s = name.index(s)
if u > s:
    print(v * product(val[s+1:u+1]))
elif u < s:
    print(v / product(val[u+1:s+1]))
else:
    print(v)
