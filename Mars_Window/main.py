current = 12 * 2018 + 3
year = int(input())
while current // 12 < year:
    current += 26
print("yes") if current // 12 == year else print("no")
