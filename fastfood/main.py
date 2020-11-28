n = 0
m = 0
prize_amount = []
prize_stickers = []
stickers = []
memo = {}

def get_memo_id(i):
    return f'{i}|{[str(i) for i in stickers]}'

def can_claim_prize(i):
    for num in prize_stickers[i]:
        if stickers[num - 1] <= 0:
            return False
    return True

def claim_prize(i):
    for num in prize_stickers[i]:
        stickers[num - 1] -= 1

def unclaim_prize(i):
    for num in prize_stickers[i]:
        stickers[num - 1] += 1

def backtrack(i):
    if (i < 0): return 0
    memo_id = get_memo_id(i)
    if memo_id in memo:
        return memo[memo_id]
    dont_claim = backtrack(i - 1)
    claim = 0
    if can_claim_prize(i):
        claim_prize(i)
        claim = prize_amount[i] + backtrack(i)
        unclaim_prize(i)
    result = max(dont_claim, claim)
    memo[memo_id] = result
    return result

T = int(input())
for _ in range(T):
    n, m = [int(i) for i in input().split()]
    prize_stickers = []
    prize_amount = []
    memo = {}
    for _ in range(n):
        line = [int(i) for i in input().split()]
        prize_stickers.append(line[1:-1])
        prize_amount.append(line[-1])
    stickers = [int(i) for i in input().split()]
    print(backtrack(n - 1))
