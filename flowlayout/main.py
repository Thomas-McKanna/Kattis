m = int(input())
while m != 0:
    rectangles = []
    prev_height = 0
    curr_height = 0
    curr_width = 0
    max_width = 0
    w, h = [int(i) for i in input().split()]
    while w != -1 or h != -1:
        if curr_width + w <= m:
            curr_height = max(curr_height, prev_height + h)
            curr_width += w
            max_width = max(max_width, curr_width)
            w, h = [int(i) for i in input().split()]
        else:
            curr_width = 0
            prev_height = curr_height
        
    print(f'{max_width} x {max(curr_height, prev_height)}')
    m = int(input())
