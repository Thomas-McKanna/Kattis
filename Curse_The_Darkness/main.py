m = int(input())
for _ in range(m):
    book_x, book_y = [float(i) for i in input().split()]
    n = int(input())
    found_candle = False
    candles = []
    for _ in range(n):
        x, y = [float(i) for i in input().split()]
        x_diff = x - book_x
        y_diff = y - book_y
        if x_diff**2 + y_diff**2 <= 64.0:
            found_candle = True
    print('light a candle') if found_candle else print('curse the darkness')
        