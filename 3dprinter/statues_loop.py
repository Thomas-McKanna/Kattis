from math import log2

num_statues = int(input())

counter = 1
while True:
    if counter >= num_statues:
        num_days = log2(counter) + 1
        print(int(num_days))
        break
    counter *= 2