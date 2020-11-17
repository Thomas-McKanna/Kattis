T = int(input())
for _ in range(T):
    num = input()
    max_ones = 0
    for i in range(len(num)):
        one_count = bin(int(num[:i+1])).count('1')
        # print(bin(int(num[-i:]))[2:])
        if one_count > max_ones:
            max_ones = one_count
    print(max_ones)
