# Submission link: https://codeforces.com/contest/1578/submission/256984580
def main():
    s = I().replace('()', '0').replace('->', ',')

    numbers = []
    ops = []
    for c in s:
        if c == '0':
            numbers.append(0)
        elif c == ',':
            ops.append(1)
        elif c == '(':
            ops.append(0)
        else:
            while ops[-1]:
                x, y = numbers.pop(), numbers.pop()
                numbers.append(max(x, y + 1))
                ops.pop()
            ops.pop()

    while ops:
        x, y = numbers.pop(), numbers.pop()
        numbers.append(max(x, y + 1))
        ops.pop()

    print(numbers[0])