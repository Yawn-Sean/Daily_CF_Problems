# Submission link: https://codeforces.com/contest/958/submission/265553196
def main():
    n, k, p = MII()
    nums = [x % p for x in MII()]

    dp = [[-p * k] * p for _ in range(k)]
    dp[0][0] = 0

    fmax = lambda x, y: x if x > y else y

    cur_acc = 0
    for i in range(n - 1):
        num = nums[i]
        cur_acc += num
        if cur_acc >= p:
            cur_acc -= p
        
        for i in range(k - 2, -1, -1):
            for j in range(p):
                dp[i+1][cur_acc] = fmax(dp[i+1][cur_acc], dp[i][j] + (cur_acc - j) % p)


    cur_acc += nums[-1]
    cur_acc %= p

    print(max(dp[k-1][j] + (cur_acc - j) % p for j in range(p)))