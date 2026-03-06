# Submission link: https://codeforces.com/gym/104891/submission/365614700
def main(): 
    n = II()
    v1 = LII()
    v2 = LII()
    
    path = [[] for _ in range(n + 1)]
    indeg = [0] * (n + 1)
    
    stk = []
    for x in v1:
        while stk and stk[-1] < x:
            stk.pop()
        if stk:
            path[stk[-1]].append(x)
            indeg[x] += 1
        stk.append(x)
    
    stk.clear()
    for x in v2:
        while stk and stk[-1] > x:
            stk.pop()
        if stk:
            path[stk[-1]].append(x)
            indeg[x] += 1
        stk.append(x)
    
    new_indeg = indeg[:]
    
    w1 = []
    pq = [i for i in range(1, n + 1) if indeg[i] == 0]
    
    while pq:
        u = heappop(pq)
        w1.append(u)
        
        for v in path[u]:
            new_indeg[v] -= 1
            if new_indeg[v] == 0:
                heappush(pq, v)
    
    new_indeg = indeg[:]
    
    w2 = []
    pq = [-i for i in range(n, 0, -1) if indeg[i] == 0]
    
    while pq:
        u = -heappop(pq)
        w2.append(u)
        
        for v in path[u]:
            new_indeg[v] -= 1
            if new_indeg[v] == 0:
                heappush(pq, -v)
    
    if v1 == w1 and v2 == w2:
        edges = [f'{u} {v}' for u in range(n + 1) for v in path[u]]
        print('Yes')
        print(len(edges))
        if len(edges): print('\n'.join(edges))
    else:
        print('No')