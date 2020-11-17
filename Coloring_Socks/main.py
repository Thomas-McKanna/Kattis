S, C, K = [int(i) for i in input().split()]
socks = sorted([int(i) for i in input().split()])
load_size = 0
first_color_in_load = socks[0]
count = 0
for sock in socks:
    if load_size == C:
        count += 1
        load_size = 1
        first_color_in_load = sock
    elif sock - first_color_in_load <= K:
        load_size += 1
    else:
        count += 1
        load_size = 1
        first_color_in_load = sock
if load_size > 0:
    count += 1
print(count)
