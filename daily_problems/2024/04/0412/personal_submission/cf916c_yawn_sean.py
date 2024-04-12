# Submission link: https://codeforces.com/contest/916/submission/256182492
def main():
    n, m = MII()
    prime = 998244353

    outs = [f'{prime} {prime}']
    for i in range(1, n - 1):
        outs.append(f'{i} {i + 1} {1}')
    outs.append(f'{n - 1} {n} {prime - (n - 2)}')

    m -= n - 1
    for j in range(n):
        if m == 0: break
        for i in range(j - 1):
            if m == 0: break
            outs.append(f'{i + 1} {j + 1} {10 ** 9}')
            m -= 1

    print('\n'.join(outs))