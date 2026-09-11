# Submission link: https://codeforces.com/gym/103426/submission/390317509
def main():
    n = II()
    grid = [LII() for _ in range(n - 1)]
    
    vis = [0] * (n + 1)
    cnt = [0] * (n + 1)
    
    for i in range(n):
        for j in range(n - 1):
            vis[grid[j][i]] = 1
    
        c = 0
        target = 0
        
        for j in range(1, n + 1):
            if vis[j] == 0:
                c += 1
                target = j
        
        if c == 1: cnt[target] += 1
        
        for j in range(n - 1):
            vis[grid[j][i]] = 0
    
    ans0 = 0
    ans1 = 1
    
    resid = n
    mod = 10 ** 9 + 7
    
    for i in range(n + 1):
        if cnt[i]:
            ans0 += 1
            ans1 = ans1 * cnt[i] % mod
            resid -= 1
    
    for i in range(1, resid + 1):
        ans1 = ans1 * i % mod
    
    print(ans0, ans1)