# Submission link: https://codeforces.com/gym/105315/submission/376177220
def main():
    t = II()
    outs = []
    
    bound = 10 ** 18
    
    for _ in range(t):
        n, k = MII()
        v1 = []
        v2 = []
        
        for _ in range(n):
            x, y = MII()
            v1.append(x)
            v2.append(y)
        
        st_range = sorted(range(n), key=lambda x: v2[x])
        
        ans = -bound
        
        cur = 0
        pq = []
        
        for i in st_range:
            if len(pq) == k - 1:
                ans = fmax(ans, cur + v1[i] - v2[i])
            
            cur += v1[i]
            heappush(pq, v1[i])
            
            if len(pq) == k:
                cur -= heappop(pq)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))