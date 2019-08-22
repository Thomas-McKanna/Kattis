
input()

durations = sorted(
    list(map(int, input().split())),
    reverse=True
)

longest = 1
count = 1

for duration in durations:
    count += 1
    longest -= 1
    if duration > longest:
        longest = duration

print(count + longest)