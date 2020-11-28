from sys import exit

S = input()
P = input()

# identical
if P == S:
    print("Yes")
    exit(0)

# prepend or append single digit
for i in range(10):
    if str(i) + P == S or P + str(i) == S:
        print("Yes")
        exit(0)

# reverse case
new_P = ''
for c in P:
    if c.isupper(): new_P += c.lower()
    elif c.islower(): new_P += c.upper()
    else: new_P += c
if new_P == S:
    print("Yes")
    exit(0)

print("No")
