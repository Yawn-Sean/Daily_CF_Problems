# Submission link: https://codeforces.com/contest/689/submission/277586237
def main():
    def check(m):
        cnt = 0
        for x in range(2, m + 1):
            cnt += m // x // x // x
            if m < x * x * x: break
        return cnt

    target = II()
    l, r = 1, target * 8
    while l <= r:
        m = (l + r) // 2
        if check(m) >= target: r = m - 1
        else: l = m + 1

    print(l if check(l) == target else -1)