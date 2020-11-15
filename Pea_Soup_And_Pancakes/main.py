n = int(input())
found_place = False
for _ in range(n):
    k = int(input())
    name = input()
    menu = set()
    for _ in range(k):
        menu.add(input())
    if 'pea soup' in menu and 'pancakes' in menu:
        print(name)
        found_place = True
        break
if not found_place:
    print('Anywhere is fine I guess')
