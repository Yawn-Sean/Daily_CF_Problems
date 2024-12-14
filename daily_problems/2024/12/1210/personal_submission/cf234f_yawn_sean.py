# Submission link: https://codeforces.com/contest/234/submission/295813981
def main():
    fin = open('input.txt', 'r')
    fout = open('output.txt', 'w')

    input = lambda: fin.readline().strip()

    def print(x):
        fout.write(str(x))

    n = II()
    a, b = MII()
    nums = [0] + LII()

    tot = sum(nums)
    inf = 10 ** 9 

    dp = [[inf] * (tot + 1) for _ in range(2)]
    ndp = [[inf] * (tot + 1) for _ in range(2)]

    dp[0][0] = 0
    dp[1][0] = 0

    for i in range(1, n + 1):
        cost = fmin(nums[i], nums[i - 1])
        for j in range(2):
            for c in range(tot + 1):
                for nj in range(2):
                    if c + nums[i] * nj <= tot:
                        ndp[nj][c + nums[i] * nj] = fmin(ndp[nj][c + nums[i] * nj], dp[j][c] + (j ^ nj) * cost)
        
        for j in range(2):
            for c in range(tot + 1):
                dp[j][c] = ndp[j][c]
                ndp[j][c] = inf

    ans = inf
    for j in range(2):
        for c in range(tot + 1):
            if c <= a and tot - c <= b:
                ans = fmin(ans, dp[j][c])

    print(ans if ans < inf else -1)