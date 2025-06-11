# 不明白为什么会超内存。。
# 换cpp过了

def main():
    n = int(input())
    mod = 998244353
    dp = [0] * (n + 1)
    dp[0] = dp[1] = 1
    pre = [0] * (n + 1)
    pre[0] = pre[1] = 1
    for i in range(2, n + 1):
        dp[i] = pre[i - 1]
        pre[i] = dp[i] + pre[i-2]
    print(dp[n] * pow(2,-n, mod) % mod)
def main2():
    n = int(input())
    mod = 998244353
    dp = 0
    pre = [0] * (n + 1)
    pre[0] = pre[1] = 1
    for i in range(2, n + 1):
        dp = pre[i - 1]
        pre[i] = dp + pre[i-2]
    print(dp * pow(2,-n, mod) % mod)
main2()