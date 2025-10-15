# Submission link: https://codeforces.com/problemset/submission/690/325341904
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, r = MII()
        vals = LII()
        outs.append((r - sum(vals)) % n + 1)

    print('\n'.join(map(str, outs)))