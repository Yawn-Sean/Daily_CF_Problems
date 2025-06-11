# Submission link: https://codeforces.com/contest/507/submission/292402039
def main():
    h, n = MII()

    def f(l, r, cur_step, d):
        if d == 0: return 0
        m = (l + r) // 2
        ans = 1 << d if (n <= m) == cur_step else 1
        ans += f(l, m, 1, d - 1) if n <= m else f(m + 1, r, 0, d - 1)
        return ans    

    print(f(1, 1 << h, 0, h))