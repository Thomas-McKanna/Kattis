from math import ceil
from sys import exit
V = int(input())
cube_root = ceil(V**(1/3))
best = 99999999
for x in range(1, V + 1):
    if V % x != 0: continue
    for y in range(1, V + 1):
        if V % y != 0: continue
        if x * y > V: break
        for z in range(1, ceil(V**(1/3)) + 1):
            if V % z != 0: continue
            if x * y * z > V: break
            if x * y * z == V:
                result = 2 * x * y + 2 * y * z + 2 * x * z
                if result < best:
                    best = result
print(best)
