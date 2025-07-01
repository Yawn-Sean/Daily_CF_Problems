t=II()
s=[ LFI() for i in range(t)]
s.sort( key=lambda  x:x[2])
# print(s)
dp=[0]*t
def f (a,b ):
    return (b[2]-a[2 ])**2<(b[1 ]-a [1 ])**2+(b[0]-a[0])**2

# dp[0]=s [0][3 ]
for i in range(t ):
    dp[i]=max(s[i][3],dp[i])
    for j in range(i+1,t ):
        if not f(s[i],s[j]):
            dp[j]=max(dp[j],dp[i]+s[j][3])
print(max(dp))
