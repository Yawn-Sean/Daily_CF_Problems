def solve():
    n=II()
    x=[0]*n;c=[0]*n
    for i in range(n):
        x[i],c[i]=MII()
    st=list(zip(x,c))
    st.sort()
    x=[0]*n;c=[0]*n
    for i in range(n):
        x[i],c[i]=st[i]
    pre=[0]*n
    for i in range(1,n):
        pre[i]=pre[i-1]+x[i]-x[i-1]
    pre_s=[0]*n
    for i in range(1,n):
        pre_s[i]=pre_s[i-1]+pre[i]
    dp=[[inf]*2 for i in range(n)]
    dp[0][0]=inf
    dp[0][1]=c[0]
    for i in range(1,n):
        for j in range(i):
            dp[i][0]=min(dp[i][0],dp[j][1]+pre_s[i]-pre_s[j]-pre[j]*(i-j))
        dp[i][1]=min(dp[i-1])+c[i]
    print(min(dp[n-1]))
    return
