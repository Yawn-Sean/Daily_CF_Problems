'''
https://codeforces.com/gym/106189/submission/349033312
'''
def solve(n: int, a: list[int]) -> list[int]:
    dp = [[0] * n for _ in range(n)]
    
    for d in range(1, n):
        l, r = 0, d
        while r < n:
            x, y = a[l], a[r]
            dp[l][r] = dp[l + 1][r - 1]
            if pmax(x, y) % pmin(x, y) == 0:
                dp[l][r] += 2
            
            for p in range(l, r):
                dp[l][r] = pmax(dp[l][r], dp[l][p] + dp[p + 1][r])

            l, r = l + 1, r + 1
    
    vis = [False] * n
    
    def findans(l, r):
        nonlocal vis
        if l < r:
            for p in range(l, r):
                if dp[l][r] == dp[l][p] + dp[p + 1][r]:
                    findans(l, p)
                    findans(p + 1, r)
                    break 
            else:
                x, y = a[l], a[r]
                if pmax(x, y) % pmin(x, y) == 0:
                    vis[l] = vis[r] = True
                findans(l + 1, r - 1)
    
    findans(0, n - 1)    
    return [i + 1 for i in range(n) if not vis[i]]
