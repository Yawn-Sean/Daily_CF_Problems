# Submission link: https://codeforces.com/problemset/submission/883/310963543
def main():
    n = II()
    v1 = []
    v2 = []

    for _ in range(n):
        s, g = MII()
        v1.append(s)
        v2.append(s + g)

    for i in range(1, n):
        v2[i] = fmin(v2[i], v2[i - 1] + 1)

    for i in range(n - 2, -1, -1):
        v2[i] = fmin(v2[i], v2[i + 1] + 1)

    total = 0

    flg = True
    for i in range(n):
        total += v2[i] - v1[i]

        if v1[i] > v2[i]:
            flg = False

    if flg:
        print(total)
        print(' '.join(map(str, v2)))
    else:
        print(-1)