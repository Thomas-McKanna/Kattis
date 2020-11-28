l, w = [int(i) for i in input().split()]
answer = ''
while l > 0 and w > 0:
    if w > 26 and w - 26 > l:
        answer += 'z'
        w -= 26
        l -= 1
    elif l > 1:
        answer += 'a'
        w -= 1
        l -= 1
    elif ord('a') + w - 1 <= ord('z'):
        answer += chr(ord('a') + w - 1)
        w = 0
        l -= 1
    else: break
print('impossible') if l > 0 else print(answer)
