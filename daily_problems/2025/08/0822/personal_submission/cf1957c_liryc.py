'''
https://codeforces.com/problemset/submission/1957/334969035
'''
# counting
dp = [0] * 300001
def init():
    global dp
    dp[0] = dp[1] = 1
    for i in range(2, 300001):
        dp[i] = (dp[i - 1] + 2 * (i - 1) * dp[i - 2]) % 1000000007

def solve():
    global dp
    n, k = map(int, input().split())
    for _ in range(k):
        r, c = map(int, input().split())
        n -= 1 + (r != c)
    return dp[n]

if __name__ == '__main__':
    init()
    for _ in range(int(input())):
        ans = solve()
        print(ans)
