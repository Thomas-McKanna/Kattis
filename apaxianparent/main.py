Y, P = input().split()
if Y[len(Y) - 2:] == 'ex':
    print(Y + P)
elif Y[-1] in ['a', 'e', 'i', 'o', 'u']:
    print(Y[:-1] + 'ex' + P)
else:
    print(Y + 'ex' + P)
