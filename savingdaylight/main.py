try:
    while True:
        month, day, year, sunrise, sunset = input().split()
        sunrise_hr, sunrise_min = [int(i) for i in sunrise.split(':')]
        sunset_hr, sunset_min = [int(i) for i in sunset.split(':')]
        diff_hr = sunset_hr - sunrise_hr
        diff_min = sunset_min - sunrise_min
        if diff_min < 0:
            diff_hr -= 1
            diff_min = 60 + diff_min
        print(f'{month} {day} {year} {diff_hr} hours {diff_min} minutes')
except:
    pass
