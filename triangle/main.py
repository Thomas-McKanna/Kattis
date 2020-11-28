from math import floor

try:
    case = 1
    while True:
        i = int(input())
        circumference = floor((1 / 2**i) * 3**(i + 1))
        answer = 0
        while circumference != 0:
            circumference //= 10
            answer += 1
        print(f'Case {case}: {answer}')
        case += 1
except:
    pass
