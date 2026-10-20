# Submission link: https://codeforces.com/gym/103577/submission/395304371
def main():
    n, q = MII()
    nums = LII()
    
    path = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
    
    vals = LII()
    
    dp = 1
    for x in vals:
        dp |= dp << x
    
    res = [int(x) for x in reversed(bin(dp)[2:])]
    k = len(res)
    
    modi = [i for i in range(k) if res[i]]
    
    parent = [-1] * n
    que = [0]
    
    for u in que:
        for v in path[u]:
            if parent[u] != v:
                parent[v] = u
                que.append(v)
    
    flg = True
    
    for u in reversed(que):
        w = 0
        for v in path[u]:
            if parent[v] == u:
                w = fmax(w, nums[v])
        
        if w <= nums[u]: continue
    
        p = bisect.bisect_left(modi, w - nums[u])
        
        if p == len(modi):
            flg = False
        else:
            nums[u] += modi[p]
    
    print(sum(nums) if flg else -1)