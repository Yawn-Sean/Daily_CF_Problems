'''
https://codeforces.com/gym/105833/submission/341264331
'''
pmax = lambda x, y: y if y > x else x
pmin = lambda x, y: y if y < x else x
def solve(n: int, ha: list[int], da: list[int], ca: list[int]) -> int:
    dp = [-1000000001] * 5001
    dp[0] = 0
    for i in range(n - 1, -1, -1):
        for j in range(5000, -1, -1):
            k = pmin(j + da[i], 5000)
            dp[k] = pmax(dp[k], dp[j] - ca[i])
        for j in range(5001):
            dp[j] += pmin(j, ha[i])
    return max(dp)
