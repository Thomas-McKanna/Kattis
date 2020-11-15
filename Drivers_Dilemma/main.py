C, X, M = [float(i) for i in input().split()]
C = C / 2
speeds = []
efficiencies = []
for _ in range(6):
    speed, efficiency = input().split()
    speeds.append(int(speed))
    efficiencies.append(float(efficiency))
speeds.reverse()
efficiencies.reverse()
found_valid_speed = False
for i in range(len(speeds)):
    time = M / speeds[i]
    if (C - X * time) * efficiencies[i] >= M:
        print("YES", speeds[i])
        found_valid_speed = True
        break
if not found_valid_speed:
    print("NO")
