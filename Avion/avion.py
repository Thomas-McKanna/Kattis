found = False
blimps = []
for i in range(5):
    code = input()
    if "FBI" in code:
        blimps.append(i + 1)
        found = True
if found:
    print(' '.join([str(i) for i in blimps]))
else:
    print("HE GOT AWAY!")
