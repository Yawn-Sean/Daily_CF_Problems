#题解：https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/11/1118/solution/cf717d.md
def main():
    n,x = map(int,input().split())
    g = list(map(float,input().split()))
    def mul(g1, g2):
        ans = [0] * 128
        for i in range(128):
            for j in range(128):
                ans[i ^ j] += g1[i] * g2[j]
        return ans

    def quickPow(grid, n):
        if n == 1: return grid
        ans = quickPow(grid, n // 2)
        ans = mul(ans, ans)
        if n % 2: ans = mul(ans, grid)
        return ans

    grid = [0] * 128

    for i in range(x + 1):
        grid[i] = g[i]

    print(1 - quickPow(grid, n)[0])

main()