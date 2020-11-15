DOUBLES = ['11', '22', '33', '44', '55', '66']

s0, s1, r0, r1 = input().split()
while '0' not in s0 + s1 + r0 + r1:
    if int(s0) < int(s1):
        roll1 = s1 + s0
    else:
        roll1 = s0 + s1
    if int(r0) < int(r1):
        roll2 = r1 + r0
    else:
        roll2 = r0 + r1
    if roll1 ==roll2:
        print("Tie.")
    # 12 or 21
    elif (roll1 == '12' or roll1 == '21') and (roll2 == '12' or roll2 == '21'):
        print("Tie.")
    elif roll1 == '12' or roll1 == '21':
        print("Player 1 wins.")
    elif roll2 == '12' or roll2 == '21':
        print("Player 2 wins.")
    # doubles
    elif roll1 in DOUBLES and roll2 in DOUBLES:
        if DOUBLES.index(roll1) > DOUBLES.index(roll2):
            print("Player 1 wins.")
        else:
            print("Player 2 wins.")
    elif roll1 in DOUBLES:
        print("Player 1 wins.")
    elif roll2 in DOUBLES:
        print("Player 2 wins.")
    # higher value
    else:
        if int(roll1) > int(roll2):
            print("Player 1 wins.")
        else:
            print("Player 2 wins.")
    s0, s1, r0, r1 = input().split()
