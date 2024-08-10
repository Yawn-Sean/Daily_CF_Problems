from math import inf
def  main():
    q = int(input())
    for _ in range(q):
        n,k = map(int,input().split())
        s = input()
        mp = {}
        mp['R'] = 0
        mp['G'] = 1
        mp['B'] = 2
        ans = inf
        for f in range(3):
            dp = [0] * (n + 1)
            for i in range(n):
                dp[i + 1] = dp[i] + int(mp[s[i]] != (f + i) % 3)
                if i >= k - 1:
                    ans = min(ans, dp[i + 1] - dp[i + 1 - k])  
        print(ans) 

main()