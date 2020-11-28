def get_substr_count(S, L):
    count = 0
    for i in range(len(L) - len(S) + 1):
        if S == L[i:i+len(S)]:
            count += 1
    return count

line = input()
while line != '0':
    S, L = line.split()
    type1 = get_substr_count(S, L)
    type2 = 0
    seen = set()
    for i in range(len(S)):
        new_S = S[:i] + S[i+1:]
        if new_S not in seen:
            seen.add(new_S)
            type2 += get_substr_count(new_S, L)
    type3 = 0
    seen = set()
    for i in range(len(S) + 1):
        for c in ['A', 'G', 'C', 'T']:
            new_S = S[:i] + c + S[i:]
            if new_S not in seen:
                seen.add(new_S)
                type3 += get_substr_count(new_S, L)
    print(type1, type2, type3)
    line = input()
