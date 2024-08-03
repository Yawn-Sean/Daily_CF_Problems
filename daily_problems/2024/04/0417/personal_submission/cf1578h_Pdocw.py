def main():
    s = I().replace("()", "0").replace("->", ",")
    numbers = []
    ops = []
    for c in s:
        if c == "0":
            numbers.append(0)
        # 用数字代表两种操作
        elif c == ",":
            ops.append(1)
        elif c == "(":
            ops.append(0)
        else:
            while ops[-1]:
                x, y = numbers.pop(), numbers.pop()
                numbers.append(max(x, y + 1))
                ops.pop()
            ops.pop() # pop "("
    while ops:
        x, y = numbers.pop(), numbers.pop()
        numbers.append(max(x, y + 1))
        ops.pop()

    print(numbers[0])
    return
