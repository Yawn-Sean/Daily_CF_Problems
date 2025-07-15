# Submission link: https://codeforces.com/contest/2048/submission/329060066
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, m = MII()
        if m >= 2 * n: outs.append('NO')
        else:
            outs.append('YES')
            for i in range(2 * n):
                outs.append(' '.join(str((i + j) % (2 * n) // 2 + 1) for j in range(m)))

    print('\n'.join(outs))