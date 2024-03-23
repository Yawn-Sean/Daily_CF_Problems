import sys
input = lambda: sys.stdin.readline().strip()

# 给定后缀数组 arr = [i1, i2, i3, i4, i5]
# 有 s[i1...] < s[i2...] < s[i3...] < s[i4...] < s[i5...] （后缀长度不一样，不可能相等）
# 有 s[i1] <= s[i2] <= s[i3] <= s[i4] <= s[i5]
# 假设 s[i1] == s[i2]，必须有 s[i1 + 1...] < s[i2 + 1...]
# 如果此条件不成立，即 i1 + 1 的 arr 下标大于 i2 + 1 的 arr 下标，必有 s[i1] < s[i2]
# 通过移除必定不存在的等号，假设有 1 <= s[i1] < s[i2] <= s[i3] < s[i4] <= s[i5] <= k，我们要尝试将等号移除
# 对于 s[i2] <= s[i3]，必有 s[i2] <= s[i3] + 1，此时左侧的式子不变，右侧的所有式子都要 + 1 来维持原来的不等关系
# 即得到 1 <= s[i1] < s[i2] < s[i3] < s[i4] + 1 <= s[i5] + 1 <= k + 1
# 同理处理 s[i4] + 1 <= s[i5] + 1，得到 1 <= s[i1] < s[i2] < s[i3] < s[i4] + 1 < s[i5] + 2 <= k + 2
# 设 x1 = s[i1]，x2 = s[i2], x3 = s[i3], x4 = s[i4] + 1, x5 = s[i5] + 2
# 则有 1 <= x1 < x2 < x3 < x4 < x5 <= k + 2，即从 [1...k+2] 这 k + 2 个数中选择 5 个不同的数，等于 (k+2)! // (k+2 - 5)! // 5!
# 进一步地，由于没处理一次小于等于，总数量都要 + 1，假设小于等于关系共有 cnt 个，最终的右边界为 k + cnt，设 k' = k + cnt
# 假设后缀数组长度为 n，最终结果为 k'! // (k' - n)! // n!，如果 n > k'，则不存在

def main():
    MOD = 998244353
    n, k = map(int, input().split())
    suffix = list(map(int, input().split()))

    seen = [-1] * n
    for i, idx in enumerate(suffix):
        seen[idx] = i

    cnt = sum([int(suffix[i] < n-1 and suffix[i+1] < n-1 and seen[suffix[i]+1] < seen[suffix[i+1]+1])
               + int(suffix[i] == n-1 and suffix[i+1] < n-1) for i in range(n-1)])
    k += cnt

    if n > k:
        print(0)
        return

    f = [1] * (k + 1)
    for i in range(1, k + 1):
        f[i] = f[i-1] * i % MOD
    g = [1] * (k + 1)
    for i in range(k + 1):
        g[i] = pow(f[i], MOD - 2, MOD)
    print(f[k] * g[k - n] % MOD * g[n] % MOD)


main()
