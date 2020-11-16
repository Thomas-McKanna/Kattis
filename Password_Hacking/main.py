N = int(input())
answer = 0
probabilities = []
for i in range(N):
    probabilities.append(float(input().split()[1]))
probabilities = sorted(probabilities, reverse=True)
for i in range(N):
    answer += (i + 1) * probabilities[i]
print(answer)
