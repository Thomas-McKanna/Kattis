C = int(input())
for _ in range(C):
    scores = [int(i) for i in input().split()][1:]
    average = sum(scores) / len(scores)
    num_above_average = [i for i in scores if i > average]
    print(f'{100 * len(num_above_average) / len(scores):.3f}%')
