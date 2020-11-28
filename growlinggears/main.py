T = int(input())
for _ in range(T):
    n = int(input())
    largest_y = 0
    largest_y_index = 0
    for i in range(n):
        a, b, c = [int(i) for i in input().split()]
        R = -b / (2 * -a)
        T = -a * (R**2) + (b * R) + c
        if T > largest_y:
            largest_y = T
            largest_y_index = i
    print(largest_y_index + 1)
