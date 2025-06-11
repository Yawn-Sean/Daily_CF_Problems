MOD = 10**9+7

def solve():
    digits = list(map(int, input()))
    k = int(input())
    if k == 0:   # 特殊处理 n=1
        return 1

    n = len(digits)
    ops = [0] * (n+1)
    for x in range(2, n+1):
        ops[x] = ops[x.bit_count()] + 1
    if k > max(ops) + 1:  # 实际上 max(ops) 最大只有 4
        return 0

    # 记忆化搜索数位 DP
    memo = [[-1] * (n+1) for _ in range(n)]
    def dp(i, ones, islim):  # ones 表示剩余 1 的数量
        if i == n:
            return ones == 0
        if ones < 0 or ones > n - i:  # 两个剪枝很重要
            return 0
        if not islim and memo[i][ones] != -1:
            return memo[i][ones]
        res = dp(i+1, ones, islim and digits[i] == 0)
        if not islim or digits[i] == 1:
            res = (res + dp(i+1, ones-1, islim and digits[i] == 1)) % MOD
        if not islim:
            memo[i][ones] = res
        return res

    if k == 1:  # 特殊处理
        return (dp(0, 1, True) - 1) % MOD  # -1 是为了排除 n=1 的情况
    ans = 0
    for ones in range(2, n+1):
        if ops[ones] + 1 == k:
            ans += dp(0, ones, True)
    return ans % MOD

print(solve())