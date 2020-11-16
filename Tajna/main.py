m = input()
R = 0
C = 0
for r in range(101):
    for c in range(101):
        if r <= c and r * c == len(m) and r > R:
            R = r
            C = c
matrix = ['' for _ in range(R)]
k = 0
for _ in range(C):
    for j in range(R):
        matrix[j] += m[k]
        k += 1
print(''.join(matrix))
