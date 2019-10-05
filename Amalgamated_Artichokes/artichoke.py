import math

def price(k):
    sin_val = math.sin(a*k + b)
    cos_val = math.cos(c*k + d)
    return p*(sin_val + cos_val + 2)

p, a, b, c, d, n = list(map(int, input().split()))

vals = [(i, price(k)) for i, k in enumerate(range(1, n + 1))]
vals = sorted(vals, key=lambda t: t[1], reverse=True)

print(vals)

# curr_max = vals[0]
# candidate_max = vals[0]

# curr_diff = 0

# for val in vals:
#     if val > curr_max or val > candidate_max:
#         candidate_max = val
    
#     if candidate_max - val > curr_diff:
#         curr_max = candidate_max
#         curr_diff = candidate_max - val
#     elif curr_max - val > curr_diff:
#         curr_diff = curr_max - val

# print(curr_diff)
