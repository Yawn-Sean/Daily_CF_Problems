# https://codeforces.com/contest/819/submission/266195075
def main():
    n = II()
    perm = LGMI()

    diff_b = [0] * (2 * n + 1)
    diff_k = [0] * (2 * n + 1)

    for i in range(n):
        l, r = n + perm[i] - i, n * 2 - 1 - i
        diff_k[l] += 1
        diff_k[r+1] -= 1
        diff_b[l] -= l
        diff_b[r+1] += l

    for i in range(2 * n):
        diff_k[i+1] += diff_k[i]
        diff_b[i+1] += diff_b[i]

    ans = [0] * n
    for i in range(2 * n):
        ans[i % n] += diff_k[i] * i + diff_b[i]

    print(min(ans) * 2, ans.index(min(ans)))
