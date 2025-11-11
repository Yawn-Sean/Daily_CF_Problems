# Submission link: https://codeforces.com/gym/105962/submission/348489447
def main(): 
    n = II()
    grid = [[int(c) for c in I()] for _ in range(n)]
    
    ans = 0
    
    cnt = [0] * n
    for i in range(n):
        for j in range(n):
            if grid[i][j]:
                cnt[j] += 1
                ans = 1
    
    for i in range(n):
        for j in range(i):
            v = 0
            w = 0
            for k in range(n):
                if grid[i][k] and grid[j][k]:
                    v += 1
                    w = fmax(w, cnt[k])
    
            ans = fmax(ans, fmin(v, w))
    
    print(ans)