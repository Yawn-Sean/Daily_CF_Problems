# Submission link: https://codeforces.com/gym/102129/submission/388650906
def main():
    k = II()
    v1 = LII()
    v2 = LII()
    
    mod = 10 ** 9 + 7
    
    xn = [[0] * k for _ in range(2 * k)]
    
    for i in range(k):
        xn[i][i] = 1
    
    for i in range(k, 2 * k):
        for j in range(k):
            for x in range(k):
                xn[i][x] += xn[i - j - 1][x] * v1[j]
                xn[i][x] %= mod
    
    def solve(x):
        if x < 2 * k: return xn[x]
        
        v = solve(x // 2)
        tag = x % 2
        
        res = [0] * (2 * k)
        
        for i in range(k):
            for j in range(k):
                res[i + j + tag] += v[i] * v[j]
                res[i + j + tag] %= mod
        
        ans = [0] * k
        
        for i in range(2 * k):
            for j in range(k):
                ans[j] += res[i] * xn[i][j]
                ans[j] %= mod
        
        return ans
    
    equations = [[0] * (k + 1) for _ in range(k)]
    
    for i in range(k):
        tmp = solve(v2[k - 1] - v2[i])
        for j in range(k):
            equations[j][i] = tmp[j]
    
    tmp = solve(v2[k - 1])
    for j in range(k):
        equations[j][k] = tmp[j]
    
    pt = 0
    
    for i in range(k):
        chosen = -1
        while pt < k + 1 and chosen == -1:
            for j in range(i, k):
                if equations[j][pt]:
                    chosen = j
                    break
            pt += 1
        
        pt -= 1
        
        if chosen != i:
            equations[i], equations[chosen] = equations[chosen], equations[i]
        
        if pt == k + 1: break
        
        v = pow(equations[i][pt], -1, mod)
        
        for j in range(pt, k + 1):
            equations[i][j] = equations[i][j] * v % mod
        
        for j in range(i + 1, k):
            w = (-equations[j][pt]) % mod
            for x in range(pt, k + 1):
                equations[j][x] += equations[i][x] * w
                equations[j][x] %= mod
    
    for i in range(k - 1, -1, -1):
        for j in range(k + 1):
            if equations[i][j]:
                
                for x in range(i):
                    w = (-equations[x][j]) % mod
                    for y in range(j, k + 1):
                        equations[x][y] += equations[i][y] * w
                        equations[x][y] %= mod
                
                break
    
    print(' '.join(str(equations[i][k]) for i in range(k)))