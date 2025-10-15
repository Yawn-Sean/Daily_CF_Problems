'''
https://codeforces.com/problemset/submission/269/317835388
'''
def solve(n: int, m: int, sa: list[int]) -> int: # x is not necessary
    dp = [1] * n
    for i in range(n):
        for j in range(i):
            if sa[j] <= sa[i]:
                if dp[j] >= dp[i]:
                    dp[i] = dp[j] + 1
    return n - max(dp)
