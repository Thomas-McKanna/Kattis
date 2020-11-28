T = int(input())
for _ in range(T):
    input()
    Nc, Ne = [int(i) for i in input().split()]
    students = [int(i) for i in input().split()]
    students += [int(i) for i in input().split()]
    cs_avg = sum(students[:Nc]) / Nc
    ec_avg = sum(students[Nc:]) / Ne
    count = 0
    for iq in students[:Nc]:
        if ec_avg < iq < cs_avg:
            count += 1
    print(count)
