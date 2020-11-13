h, w, n = [int(i) for i in input().split()]
bricks = [int(i) for i in input().split()]
current_brick = 0
current_row = 0
can_construct_wall = True
while current_row != h:
    width_used = 0
    while width_used < w and current_brick < len(bricks):
        width_used += bricks[current_brick]
        current_brick += 1
    if width_used != w:
        can_construct_wall = False
        break
    current_row += 1
print("YES") if can_construct_wall else print("NO")
