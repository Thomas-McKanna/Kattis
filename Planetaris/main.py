n, a = [int(i) for i in input().split()]
finni = sorted([int(i) for i in input().split()])
count = 0
while count < len(finni) and a > finni[count]:
    a -= finni[count] + 1
    count += 1
print(count)
