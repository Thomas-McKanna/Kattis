x, y = [int(i) for i in input().split()]
while x != 0 or y != 0:
    answer = 0
    carry = 0
    while x != 0 or y != 0:
        x_lsd = x % 10
        y_lsd = y % 10
        intermediate = x_lsd + y_lsd + carry
        if intermediate > 9:
            answer += 1
            carry = 1
        else:
            carry = 0
        x //= 10
        y //= 10
    if answer == 0:
        print('No carry operation.')
    elif answer == 1:
        print('1 carry operation.')
    else:
        print(f'{answer} carry operations.')
    x, y = [int(i) for i in input().split()]
