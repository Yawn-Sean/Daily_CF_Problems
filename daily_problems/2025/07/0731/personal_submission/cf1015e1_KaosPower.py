n,m=map(int,input().split())
s=[list(input()) for i in range(n)]
dp=[['.' for i in range(m)] for j in range(n)]
ans=""
for i in range(1,n-1):
    for j in range(1,m-1):
        if (s[i][j]=='*' and s[i+1][j]=='*' and s[i-1][j]=='*' and s[i][j-1]=='*' and s[i][j+1]=='*'):
            x=1
            while i-x>-1 and x+i<n and j-x>-1 and x+j<m and s[i+x][j]=='*' and s[i-x][j]=='*' and s[i][j-x]=='*' and s[i][j+x]=='*':
                dp[i][j],dp[i+x][j],dp[i-x][j],dp[i][j-x],dp[i][j+x]='*','*','*','*','*'
                x+=1
            ans+=str(i+1)+" "+str(j+1)+" "+str(x-1)+chr(10)
if dp!=s:print(-1)
else:
    print(ans.count(chr(10)))
    print(ans)
