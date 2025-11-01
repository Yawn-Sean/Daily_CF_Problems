'''
https://codeforces.com/gym/104599/submission/346432254
'''
# tree dp

# pa: adjusted to 0-based and pa[0] == -1
def solve(n: int, a: list[int], pa: list[int]) -> int:
    dp = [(0, 0) for _ in range(n)]
    ans = 0
    def update(i, x):
        nonlocal dp, ans
        t1, t2 = dp[i]
        if x > t1:
            t1, t2 = x, t1
        elif x > t2:
            t2 = x
        if t1 + t2 > ans:
            ans = t1 + t2
        return t1, t2
    for i in range(n - 1, -1, -1):
        dp[i] = update(i, a[i])
        if pa[i] >= 0:
            dp[pa[i]] = update(pa[i], dp[i][0] + 1)
    return ans
