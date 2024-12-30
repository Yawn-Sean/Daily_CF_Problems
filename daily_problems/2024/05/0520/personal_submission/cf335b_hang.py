from collections import Counter
def main():
    s = input()
    c = Counter(s)
    a,b = c.most_common()[0]
    if b >= 100:
        print(a * 100)
        return
    n = len(s)
    dp = [[0] * (n) for _ in range(n)]
    for i in range(n-1, -1, -1):
        dp[i][i] = 1
        for j in range(i+1, n):
            if s[i] == s[j]:
                if j - i == 1:
                    dp[i][j] = 2
                else:
                    dp[i][j] = dp[i+1][j-1] + 2
            else:
                dp[i][j] = max(dp[i+1][j], dp[i][j-1])
    res = []
    l,r = 0,n-1
    while l < r:
        if s[l] == s[r]:
            res.append(s[l])
            l += 1
            r -= 1
        elif dp[l][r] == dp[l+1][r]:
            l += 1
        else:
            r -= 1
    ans = ''.join(res)
    if len(ans) >= 50:
        ans = ans[:50]
        print(ans + ans[::-1])

    else:
        if l == r:
            print(ans + s[l] + ans[::-1])
        else:
            print(ans + ans[::-1])


if __name__ == '__main__':
    main()