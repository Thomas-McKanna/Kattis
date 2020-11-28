n, dm = [int(i) for i in input().split()]
d = [int(i) for i in input().split()]
count = 0
while count < len(d) and d[count] > dm:
    count += 1
if count == len(d):
    print("It had never snowed this early!")
else:
    print(f"It hadn't snowed this early in {count} years!")
