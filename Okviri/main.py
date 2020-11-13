word = input()
answer = ''

# line 1
answer += '.'
for i in range(len(word)):
    if (i + 1) % 3 == 0:
        answer += '.*..'
    else:
        answer += '.#..'
answer += '\n'

# line 2
answer += '.'
for i in range(len(word)):
    if (i + 1) % 3 == 0:
        answer += '*.*.'
    else:
        answer += '#.#.'
answer += '\n'

# line 3
answer += '#'
for i in range(len(word)):
    if (i + 1) % 3 == 0:
        answer += f'.{word[i]}.*'
    elif (i + 2) % 3 == 0 and i != len(word) - 1:
        answer += f'.{word[i]}.*'
    else:
        answer += f'.{word[i]}.#'
answer += '\n'

# line 4
answer += '.'
for i in range(len(word)):
    if (i + 1) % 3 == 0:
        answer += '*.*.'
    else:
        answer += '#.#.'
answer += '\n'

# line 5
answer += '.'
for i in range(len(word)):
    if (i + 1) % 3 == 0:
        answer += '.*..'
    else:
        answer += '.#..'

print(answer)
