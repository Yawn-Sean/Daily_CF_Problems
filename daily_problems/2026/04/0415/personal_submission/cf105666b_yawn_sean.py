# Submission link: https://codeforces.com/gym/105666/submission/371141862
def main():  
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        v1 = []
        v2 = []
        
        for _ in range(n):
            p, s = MII()
            if s == 0:
                v1.append(2 * p)
                v2.append(p)
            else:
                v1.append(p)
                v2.append(2 * p)
        
        x1 = []
        x2 = []
        
        for _ in range(n):
            p, s = MII()
            if s == 0: x1.append(p)
            else: x2.append(p)
        
        x1.sort()
        
        flg = True
        pq = []
        
        for i in sorted(range(n), key=lambda x: -v1[x]):
            while x1 and x1[-1] > v1[i]:
                if len(pq) == 0:
                    flg = False
                    break
                x1.pop()
                heappop(pq)
            heappush(pq, v2[i])
        
        while x1:
            x1.pop()
            heappop(pq)
        
        if not flg: outs.append('NO')
        else:
            x2.sort()
            
            for x in x2:
                if heappop(pq) < x:
                    flg = False
            
            outs.append('YES' if flg else 'NO')
    
    print('\n'.join(outs))