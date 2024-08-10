

# @TIME
def solve(testcase):
    n, k = MI()
    s = I()
    res = inf
    
    def calc(t):
        cost = [0 for _ in range(n + 1)]
        idx = 0
        
        for i, v in enumerate(s, 1):
            cost[i] = cost[i - 1] + (v != t[idx])
            idx = (idx + 1) % 3
        
        res = inf
        l, r = 0, k
        while r <= n:
            res = min(res, cost[r] - cost[l])
            l += 1
            r += 1
        
        return res
    
    for pattern in ('RGB', 'GBR', 'BRG'):
        res = min(res, calc(pattern))
    
    print(res)

for testcase in range(II()):
    solve(testcase)
