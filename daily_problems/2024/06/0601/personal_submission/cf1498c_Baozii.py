MOD = 10 ** 9 + 7

class Solution:
    def solve(self, n: int, k: int) -> int:
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        for j in range(1, k + 1):
            dp[0][j] = 1
            for i in range(1, n + 1):
                dp[i][j] = (dp[i - 1][j] + dp[n - i][j - 1]) % MOD
        return dp[n][k]

TC = int(input())

def main():
    obj = Solution()
    ans = list()
    for _ in range(TC):
        n, k = map(int, input().split())
        ans.append(obj.solve(n, k))
    for a in ans:
        print(a)

main()
