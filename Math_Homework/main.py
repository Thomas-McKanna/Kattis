b, d, c, l = [int(i) for i in input().split()]

found_at_least_one = False
for i in range(251):
    if i * b > l: continue
    for j in range(251):
        if i * b + j * d > l: continue
        for k in range(251):
            if i * b + j * d + k * c == l:
                print(i, j, k)
                found_at_least_one = True

if not found_at_least_one:
    print("impossible")
