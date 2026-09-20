# Submission link: https://codeforces.com/gym/105109/submission/391331559
def main():
    n, k = MII()
    nums = LII()

    if k <= n:
        print(nums[k - 1])
    else:
        mod = 10 ** 9 + 6

        grid = [[0] * n for _ in range(n)]

        grid[0] = nums

        for i in range(1, n):
            grid[i][i - 1] = 1

        res = matrix_pow(grid, k - n)[0]
        
        ans = 1
        mod += 1
        
        for i in range(n):
            ans = ans * pow(nums[i], res[n - 1 - i], mod) % mod
        
        print(ans)