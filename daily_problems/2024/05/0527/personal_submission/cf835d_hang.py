def main():
    s = input()
    n = len(s)
    ans = [0] * (n + 2)
    dp = [[0] * n for _ in range(n)]
    # 字符串哈希
    # start
    h = 31
    mod = 10 ** 9 + 7
    p = [1] * (n)
    for i in range(1, n):
        p[i] = p[i - 1] * h % mod
    q = [0]
    for i in range(n):
        q.append((q[-1] * h + ord(s[i])) % mod)
    def get(l, r):
        return (q[r] - q[l - 1] * p[r - l + 1] % mod + mod) % mod
    # end

    for j in range(n):
        dp[j][j] = 1
        ans[1] += 1
        ans[2] -= 1
        for i in range(j-1, -1, -1):
            if s[i] == s[j] and i + 1 == j:
                dp[i][j] = 2
            else:
                t = (j - i + 1) // 2
                # 使用字符串哈希避免时间复杂度过高
                if get(i+1, i+t) == get(j - t + 2,j + 1):
                    if dp[i][i+t-1]:
                        dp[i][j] = dp[i][i+t-1] + 1
                    elif s[i] == s[j] and dp[i+1][j-1]:
                        dp[i][j] = 1
                elif s[i] == s[j] and dp[i+1][j-1]:
                    dp[i][j] = 1
            if dp[i][j]:
                ans[1] += 1
                ans[dp[i][j] + 1] -= 1
    for i in range(1, n + 2):
        ans[i] += ans[i - 1]
    ans = ans[1:n+1]
    print(*ans)

if __name__ == '__main__':
    main()