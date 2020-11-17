from sys import exit

def get_counts(S):
    counts = {}
    S = S + '$'
    num = ''
    current_symbol = S[0]
    for i in range(1, len(S)):
        if S[i].isalpha() or S[i] == '$':
            val = 1 if num == '' else int(num)
            if current_symbol in counts:
                counts[current_symbol] += val
            else:
                counts[current_symbol] = val
            current_symbol = S[i]
            num = ''
        else:
            num += S[i]
    return counts

S, k = input().split()
k = int(k)

S_counts = get_counts(S)
for i in S_counts.keys():
    S_counts[i] *= k

T = input()
T_counts = get_counts(T)
can_make = True
answer = []
for i in T_counts.keys():
    if i in S_counts:
        answer.append(S_counts[i] // T_counts[i])
    else:
        print(0)
        exit(0)
print(min(answer))
