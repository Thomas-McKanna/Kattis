N = int(input())
ingredients = []
for _ in range(N):
    s, b = [int(i) for i in input().split()]
    ingredients.append((s, b))
best = 1000000001
for i in range(1, 2**N):
    sour = []
    bitter = []
    j = 0
    while i != 0:
        if i & 1:
            sour.append(ingredients[j][0])
            bitter.append(ingredients[j][1])
        i = i >> 1
        j += 1
    product_sour = 1
    for s in sour:
        product_sour *= s
    sum_bitter = 0
    for b in bitter:
        sum_bitter += b
    abs_diff = abs(product_sour - sum_bitter)
    if abs_diff < best:
        best = abs_diff
print(best)
