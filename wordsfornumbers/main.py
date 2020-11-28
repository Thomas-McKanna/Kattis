map = {
    0: 'zero',
    1: 'one',
    2: 'two',
    3: 'three',
    4: 'four',
    5: 'five',
    6: 'six',
    7: 'seven',
    8: 'eight',
    9: 'nine',
    10: 'ten',
    11: 'eleven',
    12: 'twelve',
    13: 'thirteen',
    14: 'fourteen',
    15: 'fifteen',
    16: 'sixteen',
    17: 'seventeen',
    18: 'eighteen',
    19: 'nineteen',
    20: 'twenty',
    30: 'thirty',
    40: 'forty',
    50: 'fifty',
    60: 'sixty',
    70: 'seventy',
    80: 'eighty',
    90: 'ninety'
}

for n in [20, 30, 40, 50, 60, 70, 80, 90]:
    for i in range(1, 10):
        map[n + i] = f'{map[n]}-{map[i]}'

try:
    while True:
        line = input().split()
        translation = []
        for i in range(len(line)):
            word = line[i]
            did_replacement = False
            for j in range(100)[::-1]:
                if str(j) in word:
                    translation.append(word.replace(str(j), map[j]))
                    did_replacement = True
                    break
            if not did_replacement:
                translation.append(word)
        translation[0] = translation[0].capitalize()
        print(' '.join(translation))
except:
    pass
