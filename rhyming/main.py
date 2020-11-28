S = input()
E = int(input())
rhyme_endings = []
for _ in range(E):
    sounds = input().split()
    for s in sounds:
        if s in S and S.index(s) == len(S) - len(s):
            rhyme_endings += sounds
P = int(input())
for _ in range(P):
    last_word = input().split()[-1]
    found_rhyme = False
    for s in rhyme_endings:
        if s in last_word and last_word.index(s) == len(last_word) - len(s):
            found_rhyme = True
            break
    print('YES') if found_rhyme else print('NO')
        