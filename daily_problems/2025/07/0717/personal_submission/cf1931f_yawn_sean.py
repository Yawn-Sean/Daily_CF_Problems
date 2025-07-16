# Submission link: https://codeforces.com/contest/1931/submission/329193454
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, k = MII()
        path = [[] for _ in range(n)]
        indeg = [0] * n
        
        for _ in range(k):
            vals = LGMI()
            
            for i in range(2, n):
                indeg[vals[i]] += 1
                path[vals[i - 1]].append(vals[i])
        
        cnt = 0
        stk = [i for i in range(n) if indeg[i] == 0]
        
        while stk:
            u = stk.pop()
            cnt += 1
            
            for v in path[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    stk.append(v)
        
        outs.append('YES' if cnt == n else 'NO')
    
    print('\n'.join(outs))