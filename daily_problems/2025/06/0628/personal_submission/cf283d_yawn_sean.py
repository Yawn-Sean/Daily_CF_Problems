# Submission link: https://codeforces.com/contest/283/submission/326349856
def main():
    n = II()

    nums = LII()
    cnt2 = [0] * n

    for i in range(n):
        while nums[i] % 2 == 0:
            nums[i] //= 2
            cnt2[i] += 1

    dp = [1] * n
    for i in range(n):
        for j in range(i):
            if nums[j] % nums[i] == 0 and (cnt2[i] - cnt2[j] == i - j or cnt2[i] <= i - j - 1):
                dp[i] = fmax(dp[i], dp[j] + 1)

    print(n - max(dp))