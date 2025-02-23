# Submission link: https://codeforces.com/contest/82/submission/297169671
def main():
    n = II()
    nums = LII()

    inf = 10 ** 9

    vn = n
    if n % 2 == 0:
        vn += 1
        nums.append(0)

    dp = [[inf] * vn for _ in range(n // 2 + 1)]
    pre = [[-1] * vn for _ in range(n // 2 + 1)]

    dp[0][0] = 0

    for i in range(n // 2):
        for j in range(2 * i + 1):
            v = fmax(nums[j], nums[2 * i + 1]) + dp[i][j]
            if v < dp[i + 1][2 * i + 2]:
                dp[i + 1][2 * i + 2] = v
                pre[i + 1][2 * i + 2] = j
            
            v = fmax(nums[j], nums[2 * i + 2]) + dp[i][j]
            if v < dp[i + 1][2 * i + 1]:
                dp[i + 1][2 * i + 1] = v
                pre[i + 1][2 * i + 1] = j
            
            v = fmax(nums[2 * i + 1], nums[2 * i + 2]) + dp[i][j]
            if v < dp[i + 1][j]:
                dp[i + 1][j] = v
                pre[i + 1][j] = j

    ans, idx = inf, -1
    for i in range(vn):
        if dp[n // 2][i] + nums[i] < ans:
            ans = dp[n // 2][i] + nums[i]
            idx = i

    print(ans)

    outs = []
    if idx < n: outs.append(str(idx + 1))

    for i in range(n // 2, 0, -1):
        nidx = pre[i][idx]
        if idx == 2 * i - 1: pair = (nidx, 2 * i)
        elif idx == 2 * i: pair = (nidx, 2 * i - 1)
        else: pair = (2 * i - 1, 2 * i)
        outs.append(' '.join(str(x + 1) for x in pair if x < n))
        idx = nidx

    print('\n'.join(reversed(outs)))