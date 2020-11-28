from random import randint
import subprocess

for i in range(1, 30 + 1):
    with open(f'secret/{i}.in', 'w') as f:
        n = randint(1, 100000)
        f.write(f'{n}\n')
        for j in range(n):
            f.write(f'{randint(0, 1e9)}\n')
