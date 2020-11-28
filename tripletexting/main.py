t = input()
w1 = t[:len(t) // 3]
w2 = t[len(t) // 3: 2 * len(t) // 3]
w3 = t[2 * len(t) // 3:]
if w1 == w2:
    print(w1)
elif w1 == w3:
    print(w1)
else:
    print(w2)
