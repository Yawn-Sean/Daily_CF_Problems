# Submission link: https://codeforces.com/contest/1042/submission/298479663
def main():
    n = II()
    nums = LII()

    pos = []
    neg = []
    zero = []

    for i in range(n):
        if nums[i] > 0: pos.append(i)
        elif nums[i] < 0: neg.append(i)
        else: zero.append(i)

    neg.sort(lambda x: -nums[x])

    outs = []

    while len(neg) > 1:
        i1, i2 = neg.pop(), neg.pop()
        outs.append(f'1 {i1 + 1} {i2 + 1}')
        pos.append(i2)

    while len(pos) > 1:
        i1, i2 = pos.pop(), pos.pop()
        outs.append(f'1 {i1 + 1} {i2 + 1}')
        pos.append(i2)

    while len(zero) > 1:
        i1, i2 = zero.pop(), zero.pop()
        outs.append(f'1 {i1 + 1} {i2 + 1}')
        zero.append(i2)

    if len(neg) == 0:
        if len(zero) and len(pos):
            outs.append(f'2 {zero.pop() + 1}')
    else:
        if len(zero):
            idx = zero.pop()
            outs.append(f'1 {neg.pop() + 1} {idx + 1}')
            if len(pos): outs.append(f'2 {idx + 1}')
        else:
            outs.append(f'2 {neg.pop() + 1}')

    print('\n'.join(outs))