P = int(input())
for _ in range(P):
    set_number, number = input().split()
    answer = []
    try: answer.append(int(number, 8))
    except: answer.append('0')
    answer.append(int(number, 10))
    answer.append(int(number, 16))
    print(f'{set_number} {" ".join([str(i) for i in answer])}')
