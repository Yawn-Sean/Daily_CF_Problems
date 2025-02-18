def main():
    n,m = map(int,input().split())
    a = []
    for _ in range(n): a.append(list(map(int,input().split())))
    dp0 = [[0]*m for _ in range(n)]
    dp1 = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if i:
                dp0[i][j] = max(dp0[i][j], dp0[i-1][j])
            if j: 
                dp0[i][j] = max(dp0[i][j], dp0[i][j-1])
            
            dp0[i][j] += a[i][j]
    for i in range(n-1,-1,-1):
        for j in range(m-1,-1,-1):
            if i < n-1:
                dp1[i][j] = max(dp1[i][j], dp1[i+1][j])
            
            if j < m-1: 
                dp1[i][j] = max(dp1[i][j], dp1[i][j+1])
            
            dp1[i][j] += a[i][j]
    dp2 = [[0]*m for _ in range(n)]
    dp3 = [[0]*m for _ in range(n)]
    for i in range(n-1,-1,-1):
        for j in range(m):
            if i < n-1:
                dp2[i][j] = max(dp2[i][j], dp2[i+1][j])
            if j: 
                dp2[i][j] = max(dp2[i][j], dp2[i][j-1])
            dp2[i][j] += a[i][j]
    
    for i in range(n):
        for j in range(m-1,-1,-1):
            if i:
                dp3[i][j] = max(dp3[i][j], dp3[i-1][j])
            if j < m-1: 
                dp3[i][j] = max(dp3[i][j], dp3[i][j+1])
            dp3[i][j] += a[i][j]
    ans = 0
    for i in range(1, n-1):
        for j in range(1, m-1):
            ans = max(ans, dp0[i-1][j] + dp1[i+1][j] + dp2[i][j-1] + dp3[i][j+1])
            ans = max(ans, dp0[i][j-1] + dp1[i][j+1] + dp2[i+1][j] + dp3[i-1][j])
    
    print(ans)
            


main()