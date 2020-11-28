from math import log2, ceil
num_statues = int(input())
log_num_statues = log2(num_statues) + 1
days_needed = ceil(log_num_statues) # round up to nearest whole number
print(days_needed)