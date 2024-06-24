# Submission link: https://codeforces.com/contest/893/submission/265131858
def main():
    n, d = MII()
    nums = LII()

    ans = 0
    l, r = 0, 0
    for num in nums:
        if num == 0:
            l = max(l, 0)
            if r < 0:
                r = d
                ans += 1
        else:
            l += num
            r += num
            r = min(r, d)
            if l > d:
                print(-1)
                exit()

    print(ans)