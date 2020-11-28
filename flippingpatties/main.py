MAX_T = 43201

def chef_can(array, d, t):
    return array[t] != 2 and array[t - d] != 2 and array[t - 2 * d] != 2

def chef_assign(array, d, t):
    array[t] += 1
    array[t - d] += 1
    array[t - 2 * d] += 1

n = int(input())
chefs = [[0 for _ in range(MAX_T)]]
for _ in range(n):
    di, ti = [int(i) for i in input().split()]
    assigned_to_a_chef = False
    for chef in chefs:
        if chef_can(chef, di, ti):
            chef_assign(chef, di, ti)
            assigned_to_a_chef = True
    if not assigned_to_a_chef:
        chefs.append([0 for _ in range(MAX_T)])
        chef_assign(chefs[-1], di, ti)
print(len(chefs))
