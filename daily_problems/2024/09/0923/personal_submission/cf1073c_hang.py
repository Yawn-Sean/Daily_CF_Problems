def main():
    n = int(input())
    s = input()
    x,y = map(int,input().split())
    if abs(x) + abs(y) > n or (n & 1) != (abs(x) + abs(y)) & 1:
        exit(print(-1))
    s = s.replace("U","0").replace("D","1").replace("L","2").replace("R","3")
    dp = [[0] * 4 for _ in range(n+1)]
    for i in range(n):
        for j in range(4):
            if s[i] == str(j):
                dp[i+1][j] = dp[i][j] + 1
            else:
                dp[i+1][j] = dp[i][j]
        
    l,r = 0,n
    while l < r:
        mid = (l+r)//2
        for i in range(mid, n+1):
            U,D,L,R = dp[-1][0] - dp[i][0] + dp[i - mid][0], dp[-1][1] - dp[i][1] + dp[i - mid][1], dp[-1][2] - dp[i][2] + dp[i - mid][2], dp[-1][3] - dp[i][3] + dp[i - mid][3]
            if abs(y - (U - D)) + abs(x - (R - L)) <= mid:
                break
        else:
            l = mid + 1
            continue
        r = mid
    print(l)
    
        
main()