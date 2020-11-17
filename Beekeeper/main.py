N = int(input())
while N != 0:
    most_doubles = 0
    best_word = ''
    for _ in range(N):
        word = input()
        double_count = 0
        double_count += word.count('aa')
        double_count += word.count('ee')
        double_count += word.count('ii')
        double_count += word.count('oo')
        double_count += word.count('uu')
        double_count += word.count('yy')
        if double_count > most_doubles or best_word == '':
            most_doubles = double_count
            best_word = word
    print(best_word)
    N = int(input())
