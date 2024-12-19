'''
https://codeforces.com/problemset/submission/82/297231305
82 D
2024/12/19 Y2
2000
DP
'''
# dp[i][k] 前i个人，且k排最后，得到(不计k)的最优解
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n: int, a: list[int]):
    min_time, ans = 1999999999, [0] * n
    dp = [[0] * n for _ in range(n)]
    ci = [[0] * n for _ in range(n)]
    for i in range(2, n, 2):
        for j in range(i + 1):
            if j >= i - 1:
                k = i + i - 1 - j
                for k in range(i - 1):
                    t = dp[i - 2][k] + max(a[i + i - 1 - j], a[k])
                    if dp[i][j] == 0 or t < dp[i][j]:
                        dp[i][j] = t
                        ci[i][j] = k
            else:
                ci[i][j] = j
                dp[i][j] = dp[i - 2][j] + max(a[i], a[i - 1])
    if n & 1:
        k = 0
        min_time = dp[n - 1][0] + a[0]
        for j in range(1, n):
            t = dp[n - 1][j] + a[j]
            if t < min_time:
                min_time, k = t, j
        ans[-1] = k + 1
        for i in range(n - 1, 1, -2):
            # (2 3) 4 (n=5)
            j = ci[i][k]
            if k >= i - 1:
                # ans[i - 2], ans[i - 1] = j, (i - 1, i) - (k)
                ans[i - 2:i] = j + 1, i + i - k
            else:
                # small k moved to tail, so ans[i - 2], ans[i - 1] = (i - 1), i
                ans[i - 2:i] = i, i + 1
            k = j
    else: # n is even
        k = 0
        min_time = dp[n - 2][0] + max(a[0], a[-1])
        for j in range(1, n - 1):
            t = dp[n - 2][j] + max(a[j], a[-1])
            if t < min_time:
                min_time, k = t, j
        ans[-2:] = k + 1, n
        for i in range(n - 2, 1, -2):
            j = ci[i][k]
            if k >= i - 1:
                ans[i - 2:i] = j + 1, i + i - k
            else:
                ans[i - 2:i] = i, i + 1
            k = j        
    return min_time, ans

if __name__ == '__main__':
    args = init()
    min_time, ans = solve(*args)
    print(min_time)
    for i in range(0, len(ans), 2):
        if i == len(ans) - 1:
            print(ans[i])
        else:
            print(ans[i], ans[i + 1])
