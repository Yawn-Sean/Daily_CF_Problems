# Submission link: https://codeforces.com/gym/106632/submission/385331155
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        v1 = LII()
        v2 = LII()
        
        cnt = [0] * n
        
        for x in v1:
            if x <= n:
                cnt[x - 1] += 1
        
        to_fill = 0
        
        total = 0
        pq = []
        
        for i in range(n):
            if cnt[i]:
                to_fill += cnt[i] - 1
                total += v2[i]
                heappush(pq, v2[i])
    
            elif to_fill:
                to_fill -= 1
                total += v2[i]
                heappush(pq, v2[i])
            
            elif pq and pq[0] < v2[i]:
                total += v2[i] - pq[0]
                heapreplace(pq, v2[i])
        
        outs.append(total)
    
    print('\n'.join(map(str, outs)))