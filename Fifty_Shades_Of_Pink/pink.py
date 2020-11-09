count = 0
n = int(input())
for _ in range(n):
    label = input().lower()
    if "pink" in label or "rose" in label:
        count += 1
if count:
    print(count)
else:
    print("I must watch Star Wars with my daughter")
    