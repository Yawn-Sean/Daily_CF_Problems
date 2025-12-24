# Submission link: https://codeforces.com/gym/106251/submission/354888913
def main(): 
    def sign(v):
        return v[1] > 0 or (v[1] == 0 and v[0] > 0)
    
    def cmp(v1, v2):
        x1, y1 = v1
        x2, y2 = v2
        val1 = y1 * x2
        val2 = y2 * x1
        if val1 < val2: return -1
        if val2 < val1: return 1
        return 0
    
    n = II()
    mod = 998244353
    
    pts_pos = []
    pts_neg = []
    
    for _ in range(n):
        pt = tuple(MII())
        if sign(pt): pts_pos.append(pt)
        else: pts_neg.append(pt)
    
    pts_pos.sort(key=cmp_to_key(cmp))
    pts_neg.sort(key=cmp_to_key(cmp))
    
    pts = pts_pos + pts_neg
    
    def check(i, j):
        x1, y1 = pts[i]
        x2, y2 = pts[j]
        
        target = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)
        v1 = x1 * x1 + y1 * y1
        v2 = x2 * x2 + y2 * y2
        
        return target > v1 and target > v2
    
    saved = [[check(i, j) for j in range(n)] for i in range(n)]
    ans = [0] * 5
    
    for i in range(n):
        dp = [[0] * n for _ in range(5)]
        dp[0][i] = 1
        
        for x in range(i, i + n):
            oj = x % n
            for v in range(3, -1, -1):
                if dp[v][oj]:
                    for y in range(x + 1, i + n):
                        nj = y % n
                        if saved[oj][nj]:
                            dp[v + 1][nj] += dp[v][oj]
        
        for x in range(5):
            for y in range(n):
                if saved[i][y]:
                    ans[x] += dp[x][y]
    
    res = n
    for i in range(1, 5):
        res += ans[i] // (i + 1)
    
    print(res % mod)