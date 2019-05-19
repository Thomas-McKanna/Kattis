import sys

word = input()
alpha = input()

keyword = set()
for c in word:
    keyword.add(c)

count = 0

for c in alpha:
    if c in keyword:
        keyword.remove(c)
        if not len(keyword):
            break
    else:
        count += 1
        if count == 10:
            print("LOSE")
            sys.exit(0)

print("WIN")
