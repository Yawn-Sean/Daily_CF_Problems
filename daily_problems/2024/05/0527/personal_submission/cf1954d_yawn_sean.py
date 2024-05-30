# Submission link: https://codeforces.com/contest/1954/submission/262814000
def main():
    mod = 998244353

    n = II()
    nums = LII()

    used_sum = [0] * 5001
    used_sum[0] = 1

    nums.sort()

    cur_sum = 0
    ans = 0
    for num in nums:
        for i in range(cur_sum, -1, -1):
            if used_sum[i]:
                ans += used_sum[i] * max((i + num + 1) // 2, num) % mod
                ans %= mod
                used_sum[i + num] += used_sum[i]
                used_sum[i + num] %= mod
        cur_sum += num

    print(ans)