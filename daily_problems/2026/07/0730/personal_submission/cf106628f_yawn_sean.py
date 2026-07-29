# Submission link: https://codeforces.com/gym/106628/submission/384690020
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        nums = LII()
        
        cur = [[] for _ in range(n)]
        pts = [0] * n
        
        def msk(x, y): return x * n + y
        
        for i in range(n):
            pq = [msk(-(cur[j][0] + math.gcd(nums[j], nums[i])), j) for j in range(i)]
            heapify(pq)
            
            for _ in range(k):
                if pq:
                    x, y = divmod(heappop(pq), n)
                    cur[i].append(-x)
                    pts[y] += 1
                    
                    if pts[y] < len(cur[y]):
                        heappush(pq, msk(-(cur[y][pts[y]] + math.gcd(nums[y], nums[i])), y))
            
            if len(cur[i]) < k: cur[i].append(0)
            
            for idx in range(i): pts[idx] = 0
        
        total_pq = []
        for x in cur:
            for y in x:
                heappush(total_pq, y)
                if len(total_pq) > k: heappop(total_pq)
        
        if len(total_pq) < k: outs.append(0)
        else: outs.append(total_pq[0])
    
    print('\n'.join(map(str, outs)))