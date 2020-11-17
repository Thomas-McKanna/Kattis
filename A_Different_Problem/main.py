try:
    while True:
        x, y = [int(i) for i in input().split()]
        print(x - y) if x > y else print(y - x)            
except:
    pass
