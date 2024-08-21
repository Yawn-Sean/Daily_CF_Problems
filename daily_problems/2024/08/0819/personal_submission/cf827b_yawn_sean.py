# Submission link: https://codeforces.com/contest/827/submission/277113373
def main():
    n, k = MII()

    x, y = divmod(n - 1, k)
    print(2 * x + min(y, 2))

    outs = []
    for i in range(1, k + 1):
        outs.append(f'{n} {i}')
    for i in range(k + 1, n):
        outs.append(f'{i - k} {i}')

    print('\n'.join(outs))