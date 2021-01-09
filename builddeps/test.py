from random_words import RandomWords
from random import choice

n = 10000
r = RandomWords()
words = [r.random_word() for _ in range(n)]

print(n)
for w in words:
    deps = ' '.join([choice(words) for _ in range(5)])
    print(f'{w}: {deps}')
print(words[0])
