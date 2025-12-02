# Submission link: https://codeforces.com/gym/105056/submission/351569362
def main(): 
    n, k, q = MII()
    nums = LII()
    parent = LII()
    
    path = [[] for _ in range(n)]
    for i in range(n - 1):
        path[parent[i] - 1].append(i + 1)
    
    updates = [[] for _ in range(n)]
    
    for qid in range(q):
        u, x = MII()
        u -= 1
        updates[u].append((qid, x))
    
    seg = SegTree(lambda x, y: x * y % k, 1, q)
    ans = [0] * n
    
    stk = [0]
    
    while stk:
        u = stk.pop()
        
        if u >= 0:
            for qid, x in updates[u]:
                seg.set(qid, x)
            
            if nums[u] % k == 0: ans[u] = 0
            else:
                res = seg.max_right(0, lambda x: x * nums[u] % k)
                ans[u] = -1 if res == q else res + 1
            
            stk.append(~u)
            for v in path[u]:
                stk.append(v)
            
        else:
            for qid, x in updates[~u]:
                seg.set(qid, 1)
    
    print(' '.join(map(str, ans)))