m, n = [int(i) for i in input().split()]
hay_dict = {}
for _ in range(m):
    line = input().split()
    hay_dict[line[0]] = int(line[1])
for _ in range(n):
    line = input()
    salary = 0
    while line != '.':
        for word in line.split():
            if word in hay_dict:
                salary += hay_dict[word]
        line = input()
    print(salary)
