'''
https://codeforces.com/gym/104879/submission/381206938
'''
def solve(n: int, m: int, t: list):
    a = [[0] * m for _ in range(n)]
    
    for j in range(m):
        fd = defaultdict(int)
        for i in range(n - 1, -1, -1):
            v = t[i][j] + i
            a[i][j] = fd[v]
            fd[v] += 1
            
    ans = 0
    for i in range(n):
        fd = defaultdict(int)
        for j in range(m - 1, -1, -1):
            v = t[i][j] + j
            b = fd[v]
            fd[v] += 1
            ans += a[i][j] * b
            
    return ans
