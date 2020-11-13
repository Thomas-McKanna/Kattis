name = input()
votes = {}
while name != '***':
    if name not in votes:
        votes[name] = 1
    else:
        votes[name] += 1
    name = input()
votes = sorted([(count, name) for name, count in votes.items()], reverse=True)
print(votes[0][1]) if votes[0][0] != votes[1][0] else print("Runoff!")
