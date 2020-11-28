N, S1, S2 = input().split()
N = int(N)
S1 = [c for c in S1]
S2 = [c for c in S2]
r = 0
s = 0
for i in range(N):
    if S1[i] == S2[i]:
        r += 1
        S1[i] = '$'
        S2[i] = '$'
S1_counts = {}
S2_counts = {}
for c in S1:
    if c in S1_counts:
        S1_counts[c] += 1
    else:
        S1_counts[c] = 1
for c in S2:
    if c in S2_counts:
        S2_counts[c] += 1
    else:
        S2_counts[c] = 1
for key in S1_counts:
    if key != '$' and key in S2_counts:
        s += min(S1_counts[key], S2_counts[key])
print(r, s)
