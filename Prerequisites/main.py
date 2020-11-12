line = input()
while line != '0':
    k, m = [int(i) for i in line.split()]
    courses = input().split()
    categories = []
    min_required = []
    for _ in range(m):
        line = input().split()
        min_required.append(int(line[1]))
        categories.append(line[2:])
    for course in courses:
        for i in range(len(categories)):
            if course in categories[i]:
                min_required[i] -= 1
    all_satisfied = [i <= 0 for i in min_required]
    print("yes") if all(all_satisfied) else print("no")
    line = input()
