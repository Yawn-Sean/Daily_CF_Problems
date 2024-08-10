# Submission Link: https://codeforces.com/contest/476/submission/268246231
def main():
    n, k = MII()

    outs = []
    outs.append(str(k * (n * 6 - 1)))

    for i in range(n):
        outs.append(f'{(6 * i + 1) * k} {(6 * i + 2) * k} {(6 * i + 3) * k} {(6 * i + 5) * k}')

    print('\n'.join(outs))