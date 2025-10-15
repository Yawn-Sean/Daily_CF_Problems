# Submission link: https://codeforces.com/contest/109/submission/321304339
def main():
    lucky_numbers = []

    def dfs(cur):
        if cur >= 10 ** 9: return
        lucky_numbers.append(cur)
        dfs(cur * 10 + 4)
        dfs(cur * 10 + 7)

    dfs(4)
    dfs(7)

    lucky_numbers.append(0)
    lucky_numbers.append(10 ** 9 + 1)
    lucky_numbers.sort()

    pl, pr, vl, vr, k = MII()
    n = len(lucky_numbers)

    ans = 0

    def calc(xl, xr, yl, yr):
        return fmax(0, fmin(xr, yr) - fmax(xl, yl) + 1)

    for i in range(n - k - 1):
        l1, r1 = lucky_numbers[i] + 1, lucky_numbers[i + 1]
        l2, r2 = lucky_numbers[i + k], lucky_numbers[i + k + 1] - 1
        
        ans += calc(l1, r1, pl, pr) * calc(l2, r2, vl, vr)
        ans += calc(l1, r1, vl, vr) * calc(l2, r2, pl, pr)

    if k == 1:
        for i in range(1, n - 1):
            if pl <= lucky_numbers[i] <= pr and vl <= lucky_numbers[i] <= vr:
                ans -= 1

    print(ans / (pr - pl + 1) / (vr - vl + 1))