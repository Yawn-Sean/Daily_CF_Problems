'''
https://codeforces.com/contest/2206/submission/382375341
Math
'''

def solve(n: int, d: int, a: list[int], b: list[int], qa: list[list[int]]):
    ia, ib = [0] * (n + 1), [0] * (n + 1)
    for i, x in enumerate(a):
        ia[x] = i
    for i, x in enumerate(b):
        ib[x] = i
        
    sd = ia[b[0]]
    for x, y in pairwise(b):
        sd += (ia[y] - ia[x] - 1) % n
    yield sd
    
    for c, x, y in qa:
        if c == 1:
            u, v = a[x - 1], a[y - 1]
            pu, pv = ib[u] + 1, ib[v] + 1
            
            if pu > pv:
                pu, pv = pv, pu
            
            if pu == 1:
                sd -= ia[b[0]]
            else:
                sd -= (ia[b[pu - 1]] - ia[b[pu - 2]] - 1) % n
            if pu < n:
                sd -= (ia[b[pu]] - ia[b[pu - 1]] - 1) % n
                
            if abs(pu - pv) != 1:
                if pv == 1:
                    sd -= ia[b[0]]
                else:
                    sd -= (ia[b[pv - 1]] - ia[b[pv - 2]] - 1) % n
                if pv < n:
                    sd -= (ia[b[pv]] - ia[b[pv - 1]] - 1) % n
            else:
                if pv < n:
                    sd -= (ia[b[pv]] - ia[b[pv - 1]] - 1) % n

            a[x - 1], a[y - 1] = a[y - 1], a[x - 1]
            ia[u], ia[v] = ia[v], ia[u]

            if pu == 1:
                sd += ia[b[0]]
            else:
                sd += (ia[b[pu - 1]] - ia[b[pu - 2]] - 1) % n
            if pu < n:
                sd += (ia[b[pu]] - ia[b[pu - 1]] - 1) % n
                
            if abs(pu - pv) != 1:
                if pv == 1:
                    sd += ia[b[0]]
                else:
                    sd += (ia[b[pv - 1]] - ia[b[pv - 2]] - 1) % n
                if pv < n:
                    sd += (ia[b[pv]] - ia[b[pv - 1]] - 1) % n
            else:
                if pv < n:
                    sd += (ia[b[pv]] - ia[b[pv - 1]] - 1) % n
        else:
            if x == 1:
                sd -= ia[b[0]]
            else:
                sd -= (ia[b[x - 1]] - ia[b[x - 2]] - 1) % n
                
            if y != x + 1:
                sd -= (ia[b[x]] - ia[b[x - 1]] - 1) % n
                sd -= (ia[b[y - 1]] - ia[b[y - 2]] - 1) % n
            else:
                sd -= (ia[b[x]] - ia[b[x - 1]] - 1) % n
            if y < n:
                sd -= (ia[b[y]] - ia[b[y - 1]] - 1) % n
                
            b[x - 1], b[y - 1] = b[y - 1], b[x - 1]
            ib[b[x - 1]], ib[b[y - 1]] = x - 1, y - 1
            
            if x == 1:
                sd += ia[b[0]]
            else:
                sd += (ia[b[x - 1]] - ia[b[x - 2]] - 1) % n
                
            if y != x + 1:
                sd += (ia[b[x]] - ia[b[x - 1]] - 1) % n
                sd += (ia[b[y - 1]] - ia[b[y - 2]] - 1) % n
            else:
                sd += (ia[b[x]] - ia[b[x - 1]] - 1) % n
            if y < n:
                sd += (ia[b[y]] - ia[b[y - 1]] - 1) % n
                
        yield sd
