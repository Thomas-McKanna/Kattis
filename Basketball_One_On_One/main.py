s = input()
A = 0
B = 0
for i in range(0, len(s), 2):
    player = s[i]
    score = int(s[i+1])
    if player == 'A':
        A += score
    else:
        B += score
    if A >= 10 and B >= 10 and B - A >= 2:
        print("B")
        break
    elif B >= 10 and A >= 10 and A - B >= 2:
        print("A")
        break
    elif A >= 11 and B <= 9:
        print("A")
        break
    elif B >= 11 and A <= 9:
        print("B")
        break
