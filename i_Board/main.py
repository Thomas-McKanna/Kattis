try:
    while True:
        line = input()
        left_down = False
        right_down = False
        for c in line:
            val = ord(c)
            for _ in range(7):
                if val & 1:
                    left_down = not left_down
                else:
                    right_down = not right_down
                val = val >> 1
        print("trapped") if left_down or right_down else print("free")
except:
    pass
