lines = []
try:
    while True:
        lines.append(input())
except:
    max_length = max([len(line) for line in lines])
    score = 0
    for line in lines[:-1]:
        score += (len(line) - max_length)**2
    print(score)
