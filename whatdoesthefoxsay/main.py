T = int(input())
for _ in range(T):
    line = ' ' + input()
    animal_noise = input()
    while animal_noise != "what does the fox say?":
        animal_noise = animal_noise.split('goes')[1].strip()
        line = line.replace(f' {animal_noise}', '')
        animal_noise = input()
    print(line.strip())
