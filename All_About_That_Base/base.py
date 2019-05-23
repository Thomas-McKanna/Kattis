def symbol_to_base(symbol):
    val = None
    if symbol.isdigit():
        val = int(symbol)
    elif symbol.isalpha():
        # 'a' is 10 and so on
        val = ord(symbol) - ord('a') + 10
    return val

def base_to_symbol(base):
    if base == 36:
        return '0'
    elif 1 <= base and base <= 9:
        return str(base)
    else:
        return chr(ord('a') + base - 10)

def to_decimal(number, base):
    """ 
    Returns the number in decimal, or None 
    if no conversion possible. 

    number should be a String
    base should be 1-36 (int)
    """
    s = 0
    position = 0
    for n in reversed(number):
        n = symbol_to_base(n)
        if n >= base and not (n == 1 and base == 1):
            return None
        s += n * (base**position)
        position += 1
    if 1 <= s and s <= 2**32 - 1:
        return s
    else:
        return None

def add(first, second):
    return first + second

def sub(first, second):
    return first - second

def mul(first, second):
    return first * second

def div(first, second):
    # division must not have a remainder
    if first % second != 0:
        return -1
    else:
        return first / second

op_to_func = {
    '+': add,
    '-': sub,
    '*': mul,
    '/': div
}

n = int(input())

for _ in range(n):
    fields = input().split()
    operand1 = fields[0]
    op = fields[1]
    operand2 = fields[2]
    result = fields[4]

    found_valid_base = False
    for i in range(1, 37):
        op1 = to_decimal(operand1, i)
        op2 = to_decimal(operand2, i)
        r = to_decimal(result, i)

        if op1 == None or op2 == None or r == None:
            continue

        if op_to_func[op](op1, op2) == r:
            found_valid_base = True
            print(base_to_symbol(i), end='') 

    if found_valid_base:
        print()
    else:
        print('invalid')
