N = int(input())
w = input()
while N > 1:
    print(f'{N} bottles of {w} on the wall, {N} bottles of {w}.')
    N -= 1
    if N == 1:
        print(f'Take one down, pass it around, {N} bottle of {w} on the wall.')
    else:
        print(f'Take one down, pass it around, {N} bottles of {w} on the wall.')
    print()
    
print(f'{N} bottle of {w} on the wall, {N} bottle of {w}.')
print(f'Take it down, pass it around, no more bottles of {w}.')
