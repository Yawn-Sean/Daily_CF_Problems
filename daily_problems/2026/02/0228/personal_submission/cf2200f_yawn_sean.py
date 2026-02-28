# Submission link: https://codeforces.com/contest/2200/submission/364774471
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        
        tmp = [[] for _ in range(n + 1)]
        for _ in range(n):
            x, y = MII()
            tmp[y].append(x)
        
        ans = 0
        to_add = [0] * (n + 1)
        
        pq = []
        cur = 0
        
        for i in range(n, -1, -1):
            for x in tmp[i]:
                heappush(pq, x)
                cur += x
            while len(pq) > i + 1:
                cur -= heappop(pq)
            
            ans = fmax(ans, cur)
            to_add[i] = cur - (pq[0] if len(pq) == i + 1 else 0)
        
        for i in range(1, n + 1):
            to_add[i] = fmax(to_add[i], to_add[i - 1])
        
        res = []
        for _ in range(m):
            x, y = MII()
            res.append(fmax(ans, to_add[y] + x))
        
        outs.append(' '.join(map(str, res)))
    
    print('\n'.join(map(str, outs)))