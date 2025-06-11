# Submission link: https://codeforces.com/contest/873/submission/279398426
def main():
    n, k = MII()
    ans = list(range(1, n + 1))

    def op(l, r):
        global k
        if k == 0 or l + 1 == r: return
        m = (l + r) // 2
        k -= 1
        ans[l:r] = ans[l+r-m:r] + ans[l:l+r-m]
        op(l, m)
        op(m, r)

    k -= 1
    if k % 2:
        exit(print(-1))
    k //= 2
    op(0, n)
    print(' '.join(map(str, ans)) if k == 0 else -1)