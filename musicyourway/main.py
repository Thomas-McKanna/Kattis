attributes = input().split()
assignments = {}
for i in range(len(attributes)):
    assignments[attributes[i]] = i
m = int(input())
songs = []
for _ in range(m):
    songs.append(input().split())
n = int(input())
for _ in range(n):
    sort_attr = input()
    index = assignments[sort_attr]
    songs = sorted(songs, key=lambda i: i[index])
    print(' '.join(attributes))
    for song in songs:
        print(' '.join(song))
    print()
