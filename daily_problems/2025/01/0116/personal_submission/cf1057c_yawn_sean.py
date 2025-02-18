# Submission link: https://codeforces.com/contest/1057/submission/301172653
def main():
    n, s, k = MII()
    s -= 1

    nums = LII()
    cols = I()

    inf = 10 ** 9

    dp = [[inf] * (k + 1) for _ in range(n)]

    for i in range(n):
        dp[i][fmin(nums[i], k)] = abs(i - s)

    st_range = sorted(range(n), key=lambda x: nums[x])

    for i in range(n):
        i1 = st_range[i]
        for j in range(n):
            j1 = st_range[j]
            if nums[i1] <= nums[j1]:
                break
            if cols[i1] != cols[j1]:
                for v in range(k + 1):
                    dp[i1][fmin(v + nums[i1], k)] = fmin(dp[i1][fmin(v + nums[i1], k)], dp[j1][v] + abs(i1 - j1))

    ans = min(dp[i][k] for i in range(n))
    print(ans if ans < inf else -1)