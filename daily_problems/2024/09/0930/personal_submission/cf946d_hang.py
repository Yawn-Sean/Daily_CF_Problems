# 题解：https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/09/0930/solution/cf946d.md
def  main():
    n,m,k = map(int,input().split())
    dp = [0] * (k + 1)
    ans = 0
    for _ in range(n):
        s = input()
        idxs = [i for i in range(m) if s[i] == '1']
        l = len(idxs)
        if l > 0:
            saved = [0] * (l + 1)
            v = idxs[-1] - idxs[0] + 1
            ans += v
            saved[l] = v
            for i in range(l):
                for j in range(i, l):
                    saved[l - (j - i + 1)] = max(saved[l - (j - i + 1)], v - (idxs[j] - idxs[i] + 1))
            for i in range(k, 0, -1):
                for j in range(l + 1):
                    if i < j: break
                    dp[i] = max(dp[i], dp[i - j] + saved[j])
    print(ans - dp[k])
        
        
        

main()
