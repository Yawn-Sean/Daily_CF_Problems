# Submission link: https://codeforces.com/gym/106368/submission/399016559
def main():
    n, D, t = MII()
    
    ds = []
    bs = []
    
    for _ in range(n):
        d, b = MII()
        ds.append(d)
        bs.append(b)
    
    to_use = [1] * n
    pq = []
    
    for i in range(n - 1, -1, -1):
        d = ds[i]
        b = bs[i]
        
        heappush(pq, bs[i] * n + i)
        
        while D - d + 1 < len(pq):
            to_use[heappop(pq) % n] = 0
    
    ans = 0
    for i in range(n):
        if to_use[i]:
            ans += bs[i]
    
    print(ans)
    
    if t == 2:
        for i in range(n - 1, 0, -1):
            to_use[i - 1] += to_use[i]
        
        for i in range(n):
            to_use[i] = fmin(D - to_use[i] + 1, D)
        
        print(' '.join(map(str, to_use)))