from collections import Counter
def main():
    s = input()
    n = len(s)
    dp = [[0] * 27 for _ in range(n + 1)]
    pre = [[0] * 27 for _ in range(n + 1)]
    last = [0] * 27
    for i in range(1, n+1):
        pre[i][ord(s[i-1]) - ord('a') + 1] += 1
        pos = last[ord(s[i-1]) - ord('a') + 1]
        cnt = -1
        dp[i][1] += 1
        for j in range(1, 27): 
            pre[i][j] += pre[i-1][j]
            cnt += 1 if pre[i][j] - pre[pos][j] else 0
            dp[i][j] += dp[i-1][j]
        for j in range(1, cnt + 1):
            dp[i][j] -= dp[i-1][j]
            dp[i][j+1] += dp[i-1][j]
        last[ord(s[i-1]) - ord('a') + 1] = i
    ans = []
    for i in range(1, 27): 
        ans.append(0)
        for j in range(1, n+1): 
            ans[-1] += dp[j][i]
        if ans[-1] == 0: 
            ans.pop()
            break
    print(len(ans))
    print(*ans,sep='\n')
    return
main()