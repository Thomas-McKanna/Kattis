C = input()
K = input()
answer = ''
for i in range(len(C)):
    if i % 2 == 0:
        answer += chr(((ord(C[i]) - ord('A')) - (ord(K[i]) - ord('A'))) % 26 + ord('A'))
    else:
        answer += chr(((ord(C[i]) - ord('A')) + (ord(K[i]) - ord('A'))) % 26 + ord('A'))
print(answer)
