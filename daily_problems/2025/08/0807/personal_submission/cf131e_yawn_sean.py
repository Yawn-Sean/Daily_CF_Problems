# Submission link: https://codeforces.com/contest/131/submission/332652622
def main():
    n, m = MII()
    
    xs = []
    ys = []
    
    for _ in range(m):
        x, y = MII()
        xs.append(x)
        ys.append(y)
    
    cnt = [0] * m
    
    tmp = [[] for _ in range(2 * n + 1)]
    
    for i in range(2 * n + 1):
        tmp[i].clear()
    
    for i in range(m):
        tmp[xs[i]].append(i)
    
    for i in range(2 * n + 1):
        tmp[i].sort(key=lambda x: ys[x])
        
        for j in range(1, len(tmp[i])):
            cnt[tmp[i][j]] += 1
            cnt[tmp[i][j - 1]] += 1
    
    for i in range(2 * n + 1):
        tmp[i].clear()
    
    for i in range(m):
        tmp[ys[i]].append(i)
    
    for i in range(2 * n + 1):
        tmp[i].sort(key=lambda x: xs[x])
        
        for j in range(1, len(tmp[i])):
            cnt[tmp[i][j]] += 1
            cnt[tmp[i][j - 1]] += 1
    
    for i in range(2 * n + 1):
        tmp[i].clear()
    
    for i in range(m):
        tmp[xs[i] + ys[i]].append(i)
    
    for i in range(2 * n + 1):
        tmp[i].sort(key=lambda x: xs[x])
        
        for j in range(1, len(tmp[i])):
            cnt[tmp[i][j]] += 1
            cnt[tmp[i][j - 1]] += 1
    
    for i in range(2 * n + 1):
        tmp[i].clear()
    
    for i in range(m):
        tmp[xs[i] - ys[i]].append(i)
    
    for i in range(2 * n + 1):
        tmp[i].sort(key=lambda x: xs[x])
        
        for j in range(1, len(tmp[i])):
            cnt[tmp[i][j]] += 1
            cnt[tmp[i][j - 1]] += 1
    
    ans = [0] * 9
    for x in cnt:
        ans[x] += 1
    
    print(*ans)