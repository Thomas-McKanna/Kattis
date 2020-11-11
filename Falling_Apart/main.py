n = int(input())
a = [int(i) for i in input().split()]
a.sort(reverse=True)
alice = 0
bob = 0
alice_turn = True
while len(a):
    if alice_turn:
        alice += a[0]
    else:
        bob += a[0]
    alice_turn = not alice_turn
    a = a[1:]
print(alice, bob)
