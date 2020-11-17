n = int(input())
s = input().split()
m = int(input())
correct = {}
incorrect = {}
dict = {}

for _ in range(m):
    d, e, c = input().split()
    if c == 'correct':
        if d in correct:
            correct[d] += 1
        else:
            correct[d] = 1
    else:
        if d in incorrect:
            incorrect[d] += 1
        else:
            incorrect[d] = 1
    dict[d] = e

all_ways = 0
for word in s:
    if word in correct:
        if word in incorrect:
            if all_ways == 0:
                all_ways = correct[word] + incorrect[word]
            else:
                all_ways *= correct[word] + incorrect[word]
        else:
            if all_ways == 0:
                all_ways = correct[word]
            else:
                all_ways *= correct[word]
    elif word in incorrect:
        if all_ways == 0:
            all_ways = incorrect[word]
        else:
            all_ways *= incorrect[word]

num_correct_ways = 0
for word in s:
    if word in correct:
        if num_correct_ways == 0:
            num_correct_ways = correct[word]
        else:
            num_correct_ways *= correct[word]
    else:
        num_correct_ways = 0
        break

if all_ways == 1:
    answer = []
    all_correct = True
    for word in s:
        answer.append(dict[word])
        if word in incorrect:
            all_correct = False
    print(' '.join(answer))
    print('correct') if all_correct else print('incorrect')
else:
    print(f'{num_correct_ways} correct')
    print(f'{all_ways - num_correct_ways} incorrect')
