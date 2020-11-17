N = int(input())
prices = [int(i) for i in input().split()]
M = int(input())
topping_prices = [int(i) for i in input().split()]
allowed_toppings = []
for _ in range(N):
    allowed_toppings.append([int(i) - 1 for i in input().split()][1:])
X = int(input())
lowest_price = 999999
for i in range(N):
    for j in allowed_toppings[i]:
        if prices[i] + topping_prices[j] < lowest_price:
            lowest_price = prices[i] + topping_prices[j]
print((X // lowest_price) - 1)
