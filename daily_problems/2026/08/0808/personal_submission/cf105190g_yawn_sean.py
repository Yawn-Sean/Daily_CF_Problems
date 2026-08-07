# Submission link: https://codeforces.com/gym/105190/submission/386014091
def main():
    t = II()
    outs = []
    
    mod = 998244353
    
    def matrix_mul(A, B):
        n, m = len(A), len(A[0])
        p = len(B[0])
        ans = [[0] * p for _ in range(n)]
        for i in range(n):
            for j in range(m):
                for k in range(p):
                    ans[i][k] += A[i][j] * B[j][k]
        for i in range(n):
            for j in range(m):
                ans[i][j] %= mod
        return ans
    
    def matrix_pow(x, n):
        if n == 0:
            k = len(x)
            grid = [[0] * k for _ in range(k)]
            for i in range(k):
                grid[i][i] = 1
            return grid
        if n == 1: return x
        if n == 2: return matrix_mul(x, x)
        v = matrix_pow(x, n // 2)
        ans = matrix_mul(v, v)
        if n % 2 == 0:
            return ans
        return matrix_mul(ans, x)
    
    for _ in range(t):
        n = II()
        p0, q0, p1, q1, p2, q2 = MII()
        
        x0 = p0 * pow(q0, -1, mod) % mod
        y0 = (mod + 1 - x0) % mod
        
        x1 = p1 * pow(q1, -1, mod) % mod
        y1 = (mod + 1 - x1) % mod
        
        x2 = p2 * pow(q2, -1, mod) % mod
        y2 = (mod + 1 - x2) % mod
        
        grid = [[x1, x2, 0],
                [y1, y2, 0],
                [x1, x2, 1]]
        
        res = matrix_pow(grid, n - 1)
        
        ans = 0
        ans += res[2][0] * x0 % mod
        ans += res[2][1] * y0 % mod
        ans += res[2][2] * x0 % mod
        
        outs.append(ans % mod)
    
    print('\n'.join(map(str, outs)))