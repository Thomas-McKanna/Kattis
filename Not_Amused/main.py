try:
    i = 1
    while True:
        input()
        customers = {}
        bills = {}
        line = input()
        while line != 'CLOSE':
            status, name, time = line.split()
            time = int(time)
            if status == 'ENTER':
                customers[name] = time
            else:
                if name in bills:
                    bills[name] += time - customers[name]
                else:
                    bills[name] = time - customers[name]
            line = input()
        print(f'Day {i}')
        for name, duration in sorted([(n, d) for n, d in bills.items()]):
            print(f'{name} ${duration * 0.10:.2f}')
        print()
        i += 1    
except:
    pass
