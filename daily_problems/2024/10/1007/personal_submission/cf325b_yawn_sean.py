# Submission link: https://codeforces.com/problemset/submission/325/284708388#
def main():
    n = II()
    flg = False

    for i in range(60):
        v = 1 << i
        l, r = 1, 2 * 10 ** 9
        while l <= r:
            m = (l + r) // 2
            if m * (m - 1) // 2 + m * (v - 1) <= n:
                l = m + 1
            else:
                r = m - 1
        if r * (r - 1) // 2 + r * (v - 1) == n and r % 2:
            print(r * v)
            flg = True

    if not flg: print(-1)