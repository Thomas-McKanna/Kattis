n = int(input())

def find_max_sequence(N, x):
    """
    N: the list of numbers
    x: the index of m
    """
    m = N[x]
    s = m
    # go as far left as possible
    current = x - 1
    while current >= 0 and N[current] > m:
        s += N[current]
        current -= 1
    # go as far right as possible
    current = x + 1
    while current < len(N) and N[current] > m:
        s += N[current]
        current += 1
    return s

for _ in range(n):
    n, m = map(int, input().split())
    N = [ int(i) for i in input().split() ]

    maximum = -1
    
    for x in range(n):
        if N[x] == m:
            value = find_max_sequence(N, x)
            if value > maximum:
                maximum = value

    print(maximum)
