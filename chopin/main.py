dict = {
    'Ab minor': 'G# minor',
    'A# major': 'Bb major',
    'A# minor': 'Bb minor',
    'C# major': 'Db major',
    'Db minor': 'C# minor',
    'D# major': 'Eb major',
    'D# minor': 'Eb minor',
    'Gb major': 'F# major',
    'Gb minor': 'F# minor',
    'G# major': 'Ab major',
    'G# minor': 'Ab minor',
    'Bb major': 'A# major',
    'Bb minor': 'A# minor',
    'Db major': 'C# major',
    'C# minor': 'Db minor',
    'Eb major': 'D# major',
    'Eb minor': 'D# minor',
    'F# major': 'Gb major',
    'F# minor': 'Gb minor',
    'Ab major': 'G# major',
}

try:
    i = 1
    while True:
        s = input()
        ans = 'UNIQUE'
        if s in dict:
            ans = dict[s]
        print(f'Case {i}: {ans}')
        i += 1
except:
    pass
