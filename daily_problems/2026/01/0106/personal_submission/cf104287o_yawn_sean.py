# Submission link: https://codeforces.com/gym/104287/submission/356459622
def main(): 
    n, q = MII()
    nums = LII()
    
    acc = list(accumulate(nums, initial=0))
    fen_k = FenwickTree(n + 1)
    fen_b = FenwickTree(n + 1)
    
    pq = []
    for i in range(1, n):
        if acc[i] <= nums[i]:
            pq.append(i)
    
    outs = []
    
    for _ in range(q):
        l, r, x = MII()
        l -= 1
        
        fen_k.add(l, x)
        fen_b.add(l, -(l - 1) * x)
        
        fen_k.add(r, -x)
        fen_b.add(r, (r - 1) * x)
        
        if l > 0:
            heappush(pq, l)
        
        while pq:
            u = pq[0]
            
            if acc[u] + fen_k.rsum(0, u - 1) * (u - 1) + fen_b.rsum(0, u - 1) <= nums[u] + fen_k.rsum(0, u):
                break
            
            heappop(pq)
    
        outs.append(-1 if len(pq) == 0 else pq[0] + 1)
    
    print('\n'.join(map(str, outs)))