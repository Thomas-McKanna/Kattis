ch, cm, cs = [int(i) for i in input().split(':')]
fh, fm, fs = [int(i) for i in input().split(':')]
current = ch * 60 * 60 + cm * 60 + cs
future = fh * 60 * 60 + fm * 60 + fs
if current > future:
    result = 24 * 60 * 60 - current + future
else:
    result = future - current
se = result % 60
result = result // 60
mi = result % 60
result = result // 60
hr = result % 60
answer = f'{str(hr).zfill(2)}:{str(mi).zfill(2)}:{str(se).zfill(2)}'
if answer == '00:00:00':
    answer = '24:00:00'
print(answer)
