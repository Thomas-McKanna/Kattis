a, b, c = input().split()

NORTH = "North"
SOUTH = "South"
EAST = "East"
WEST = "West"
YES = "Yes"

if a == NORTH and b == SOUTH and c == WEST:
    print(YES)
elif a == WEST and b == EAST and c == SOUTH:
    print(YES)
elif a == SOUTH and b == NORTH and c == EAST:
    print(YES)
elif a == EAST and b == WEST and c == NORTH:
    print(YES)
elif a == NORTH and b == EAST and (c == SOUTH or c == WEST):
    print(YES)
elif a == WEST and b == NORTH and (c == EAST or c == SOUTH):
    print(YES)
elif a == SOUTH and b == WEST and (c == NORTH or c == EAST):
    print(YES)
elif a == EAST and b == SOUTH and (c == WEST or c == NORTH):
    print(YES)
else:
    print("No")
