sides = [int(i) for i in input().split()]
while sum(sides) != 0:
    sides = sorted(sides)
    if sides[0]**2 + sides[1]**2 == sides[2]**2:
        print("right")
    else:
        print("wrong")
    sides = [int(i) for i in input().split()]
