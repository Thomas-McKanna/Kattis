p, q, s = [int(i) for i in input().split()]
blinked_at_same_time = False

current = p
p_blinks = []
while current <= s:
    p_blinks.append(current)
    current += p

current = q
q_blinks = []
while current <= s:
    q_blinks.append(current)
    current += q

for i in p_blinks:
    if i in q_blinks:
        blinked_at_same_time = True
        break

print("yes") if blinked_at_same_time else print("no")
