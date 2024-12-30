# https://codeforces.com/contest/1168/submission/259283839
# https://github.com/liketheflower/Daily_CF_Problems/tree/main/daily_problems/2024/05/0502/solution
def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    lo, hi = 0, m - 1

    def good(mid):
        curr = 0
        for num in a:
            if num == curr:
                continue
            elif num < curr:
                if curr - num > mid:
                    return False
            else:  # num > curr
                # change to curr if possible if not set curr to num
                if (m - num) + curr > mid:
                    curr = num
        return True

    while lo < hi:
        mid = (lo + hi) // 2
        if good(mid):
            hi = mid
        else:
            lo = mid + 1
    print(lo)


solve()
