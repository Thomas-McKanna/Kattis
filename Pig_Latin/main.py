VOWELS = ['a', 'e', 'i', 'o', 'u', 'y']

try:
    while True:
        words = input().split()
        answer = []
        for word in words:
            if word[0] in VOWELS:
                answer.append(f'{word}yay')
            else:
                for i in range(len(word)):
                    if word[i] in VOWELS: break
                answer.append(f'{word[i:]}{word[:i]}ay')
        print(' '.join(answer))
except:
    pass
