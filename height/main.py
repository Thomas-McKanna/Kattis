P = int(input())
for _ in range(P):
    arr = []
    count = 0
    heights = [int(i) for i in input().split()]
    case_num = heights[0]
    heights = heights[1:]
    for i in range(20):
        found_somebody_taller = False
        for j in range(len(arr)):
            if heights[i] < arr[j]:
                count += len(arr[j:])
                arr = arr[:j] + [heights[i]] + arr[j:]
                found_somebody_taller = True
                break
        if not found_somebody_taller:
            arr.append(heights[i])
    print(case_num, count)
