n = int(input())

for _ in range(n):
    s = input()
    p_len = 1
    while p_len < len(s):
        found_pattern = True
        p = s[:p_len]
        for i in range(len(s)):
            if s[i] != p[i % p_len]:
                found_pattern = False
                break
        if found_pattern:
            break
        p_len += 1
    print(p_len)
