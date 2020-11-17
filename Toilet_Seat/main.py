s = input()

policy1 = 0
seat_up = True if s[0] == 'U' else False
for c in s[1:]:
    if seat_up and c == 'U':
        policy1 += 0
    elif seat_up and c == 'D':
        policy1 += 2
    elif not seat_up and c == 'U':
        policy1 += 1
        seat_up = True
    elif not seat_up and c == 'D':
        policy1 += 1
        seat_up = True

policy2 = 0
seat_up = True if s[0] == 'U' else False
for c in s[1:]:
    if seat_up and c == 'U':
        policy2 += 1
        seat_up = False
    elif seat_up and c == 'D':
        policy2 += 1
        seat_up = False
    elif not seat_up and c == 'U':
        policy2 += 2
    elif not seat_up and c == 'D':
        policy2 += 0

policy3 = 0
seat_up = True if s[0] == 'U' else False
for c in s[1:]:
    if seat_up and c == 'U':
        policy3 += 0
    elif seat_up and c == 'D':
        policy3 += 1
        seat_up = False
    elif not seat_up and c == 'U':
        policy3 += 1
        seat_up = True
    elif not seat_up and c == 'D':
        policy3 += 0

print(policy1)
print(policy2)
print(policy3)
