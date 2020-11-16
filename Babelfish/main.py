dict = {}
line = input()
while line != '':
    english, foreign = line.split()
    dict[foreign] = english
    line = input()
try:
    while True:
        foreign = input()
        print(dict[foreign]) if foreign in dict else print("eh")
except:
    pass
