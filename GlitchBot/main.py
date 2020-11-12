import sys

LEFT = "Left"
RIGHT = "Right"
FORWARD = "Forward"
directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

x, y = [int(i) for i in input().split()]

def can_reach_goal(instructions):
    curr_x = 0
    curr_y = 0
    i = 0
    for instruction in instructions:
        if instruction == LEFT:
            i = (i - 1) % 4
        elif instruction == RIGHT:
            i = (i + 1) % 4
        else:
            curr_x += directions[i][0]
            curr_y += directions[i][1]
    return curr_x == x and curr_y == y

n = int(input())
instructions = []
for _ in range(n):
    instructions.append(input())
for i in range(n):
    original = instructions[i]
    if original == LEFT:
        substitutes = [RIGHT, FORWARD]
    elif original == RIGHT:
        substitutes = [LEFT, FORWARD]
    else:
        substitutes = [LEFT, RIGHT]
    for substitute in substitutes:
        instructions[i] = substitute
        if can_reach_goal(instructions):
            print(i + 1, substitute)
            sys.exit(0)
    instructions[i] = original
