# Submission link: https://codeforces.com/contest/362/submission/294280933
def main():
    n = II()
    perm = LGMI()

    ans = 0
    for i in range(n):
        for j in range(i):
            if perm[i] < perm[j]:
                ans += 1

    def f(x, y):
        return x * (n + 1) + y

    pref = [0] * ((n + 1) * (n + 1))
    for i in range(n):
        pref[f(i + 1, perm[i] + 1)] = 1

    for i in range(n + 1):
        for j in range(n):
            pref[f(i, j + 1)] += pref[f(i, j)]

    for i in range(n):
        for j in range(n + 1):
            pref[f(i + 1, j)] += pref[f(i, j)]

    res = -1
    cnt = 0

    for i in range(n):
        for j in range(i):
            if perm[i] < perm[j]:
                v = 2 * (pref[f(i, perm[j])] - pref[f(j + 1, perm[j])] - pref[f(i, perm[i] + 1)] + pref[f(j + 1, perm[i] + 1)]) + 1
                if v > res:
                    res = v
                    cnt = 1
                elif v == res:
                    cnt += 1

    print(ans - res, cnt)