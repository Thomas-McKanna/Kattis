n = int(input())
seen = set()
for _ in range(n):
    word = input().replace('-', ' ').lower()
    seen.add(word)
print(len(seen))
