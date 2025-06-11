# Submission link: https://codeforces.com/contest/77/submission/297985084
def main():
    t = II()
    outs = []

    for _ in range(t):
        a, b = MII()
        if b == 0: outs.append(1)
        elif a == 0: outs.append(0.5)
        elif b > a / 4: outs.append(0.5 + a / 16 / b)
        else: outs.append(1 - b / a)

    print('\n'.join(map(str, outs)))