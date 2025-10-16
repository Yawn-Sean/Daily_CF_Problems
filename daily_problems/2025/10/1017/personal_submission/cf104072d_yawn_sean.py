# Submission link: https://codeforces.com/gym/104072/submission/344020323
def main(): 
    n = II()
    grid = [LII() for _ in range(n)]
    
    u = [x[:] for x in grid]
    d = [x[:] for x in grid]
    l = [x[:] for x in grid]
    r = [x[:] for x in grid]
    
    for i in range(1, n):
        for j in range(n):
            if u[i][j]:
                u[i][j] = u[i - 1][j] + 1
    
    for i in range(n - 2, -1, -1):
        for j in range(n):
            if d[i][j]:
                d[i][j] = d[i + 1][j] + 1
    
    for i in range(n):
        for j in range(1, n):
            if l[i][j]:
                l[i][j] = l[i][j - 1] + 1
    
    for i in range(n):
        for j in range(n - 2, -1, -1):
            if r[i][j]:
                r[i][j] = r[i][j + 1] + 1
    
    def solve(x, y):
        v1 = []
        v2 = []
        
        while x < n and y < n:
            v1.append(fmin(d[x][y], r[x][y]) - 1)
            v2.append(fmin(u[x][y], l[x][y]) - 1)
            x += 1
            y += 1
        
        k = len(v1)
        
        ans = 0
        
        fen = FenwickTree(k + 1)
        tmp = [[] for _ in range(k + 1)]
        
        for i in range(k):
            tmp[i - v2[i]].append(i)
        
        for i in range(k):
            for j in tmp[i]:
                fen.add(j, 1)
            ans += fen.sum(i + v1[i])
        return ans - k * (k - 1) // 2
    
    ans = solve(0, 0)
    for i in range(1, n):
        ans += solve(0, i) + solve(i, 0)
    
    print(ans)