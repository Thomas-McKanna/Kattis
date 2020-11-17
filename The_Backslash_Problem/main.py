def escape_string(s):
    result = ''
    for c in s:
        if ord('!') <= ord(c) <= ord('*') or ord('[') <= ord(c) <= ord(']') or ord(c) == ord('\\'):
            result += '\\'
        result += c
    return result

try:
    while True:
        n = int(input())
        s = input()
        for i in range(n):
            s = escape_string(s)
        print(s)
except:
    pass
