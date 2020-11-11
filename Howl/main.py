h = input()
answer = 'AWAWHO'
diff = len(h) - len(answer)
if (diff >= 0):
    answer += 'O'*(diff + 1)
print(answer)