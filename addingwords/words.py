from sys import stdin

word_to_num = {}
num_to_word = {}

def make_calc(equation):
    """
    equation should be a list of string
    which represent the equation (not including
    the trailing '=')
    (ex. ['foo', '+', 'bar'])
    """
    result = 0
    if equation[0] not in word_to_num.keys():
        result = -999999
    else:
        result = word_to_num[equation[0]]

        i = 1
        while i < len(equation):
            op = equation[i]
            word = equation[i + 1]

            if word in word_to_num.keys():
                word = word_to_num[word]
            else:
                result = -999999
                break

            if op == '+':
                result += word
            else:
                # op == '-'
                result -= word

            i += 2

    return result
    

for line in stdin.readlines():
    fields = line.rstrip().split()

    command = fields[0]

    if command == 'def':
        word = fields[1]
        val = int(fields[2])

        if word in word_to_num.keys():
            del num_to_word[word_to_num[word]]

        word_to_num[word] = val
        num_to_word[val] = word
    elif command == 'calc':
        lhs = make_calc(fields[1:-1])
        if lhs in num_to_word.keys():
            rhs = num_to_word[lhs]
        else:
            rhs = 'unknown'

        print(' '.join(fields[1:]), rhs)
    else:
        # command == 'clear'
        word_to_num = {}
        num_to_word = {}

