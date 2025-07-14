# Submission link: https://codeforces.com/contest/1991/submission/328907061
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        if n <= 5:
            outs.append(str(n // 2 + 1))
            outs.append(' '.join(str(x // 2 + 1) for x in range(1, n + 1)))
        else:
            outs.append('4')
            outs.append(' '.join(str(x % 4 + 1) for x in range(n)))

    print('\n'.join(outs))