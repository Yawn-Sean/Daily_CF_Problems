# Submission link: https://codeforces.com/gym/105746/submission/370829931
def main(): 
    n, m, q = MII()
    
    path = [[] for _ in range(n)]
    indeg = [0] * n
    
    for _ in range(m):
        u, v, t, r = MII()
        u -= 1
        v -= 1
        path[u].append((v, t, r))
        indeg[v] += 1
    
    inf = 10 ** 16
    best_result = [[inf] * (2 * n) for _ in range(n)]
    
    best_result[0][n] = 0
    
    stk = [i for i in range(n) if indeg[i] == 0]
    while stk:
        u = stk.pop()
        
        for v, t, r in path[u]:
            for i in range(2 * n):
                if best_result[u][i] < inf:
                    best_result[v][i + r] = fmin(best_result[v][i + r], best_result[u][i] + t)
            
            indeg[v] -= 1
            if indeg[v] == 0:
                stk.append(v)
    
    total_lines = []
    
    for i in range(n):
        lines = []
        for j in range(2 * n - 1, -1, -1):
            k = j - n
            b = best_result[i][j]
            if b < inf:
                while len(lines) >= 2:
                    k1, b1 = lines[-2]
                    k2, b2 = lines[-1]
                    if (k1 - k) * (b2 - b) >= (k2 - k) * (b1 - b): lines.pop()
                    else: break
                lines.append((k, b))
        total_lines.append(lines)
    
    def solve(x, timestamp):
        left, right = 0, len(total_lines[x]) - 1
        
        while left < right:
            mid = (left + right) // 2
            k1, b1 = total_lines[x][mid]
            k2, b2 = total_lines[x][mid + 1]
            if k1 * timestamp + b1 <= k2 * timestamp + b2: right = mid
            else: left = mid + 1
        
        k, b = total_lines[x][left]
        return k * timestamp + b
    
    outs = []
    
    for _ in range(q):
        l, r, x = MII()
        x -= 1
        
        if len(total_lines[x]) == 0:
            outs.append('sorry')
        else:
            outs.append(str(fmin(solve(x, l), solve(x, r))))
    
    print('\n'.join(outs))
