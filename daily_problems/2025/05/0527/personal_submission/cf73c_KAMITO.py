def solve():
    s,K=LI()
    K=int(K)
    n=II()
    add=[[0]*26 for i in range(26)]
    for i in range(n):
        x,y,c=LI()
        c=int(c)
        add[ord(x)-ord('a')][ord(y)-ord('a')]=c
    m=len(s)
    if K==0:
        ans=0
        for i in range(1,m):
            x=ord(s[i-1])-ord('a')
            y=ord(s[i])-ord('a')
            ans+=add[x][y]
        print(ans)
        return
    dp=[[[-inf]*(26) for i in range(K+1)] for j in range(m)]
    dp[0][0][ord(s[0])-ord('a')]=0
    for i in range(26):
        dp[0][1][i]=0
    for i in range(m-1):
        x=ord(s[i+1])-ord('a')
        for j in range(min(i+1,K)+1):
            for k in range(26):
                dp[i+1][j][x]=max(dp[i+1][j][x],dp[i][j][k]+add[k][x])
                if j+1<=K:
                    for y in range(26):
                        dp[i+1][j+1][y]=max(dp[i+1][j+1][y],dp[i][j][k]+add[k][y])
    ans=-inf
    for i in range(K+1):
        for j in range(26):
            ans=max(ans,dp[m-1][i][j])
    print(ans)
    return
