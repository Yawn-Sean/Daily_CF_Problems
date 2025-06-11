mod = 998244353

def solve(testcase):
    n, k = MI()
    A = LII()
    B = LII()
    
    mp = {v: i for i, v in enumerate(A)}
    sb = set(B)
    
    res = 1
    for i in range(k):
        mult=0
        if mp[B[i]] > 0 and A[mp[B[i]] - 1] not in sb:
            mult += 1
        if mp[B[i]] + 1 < n and  A[mp[B[i]] + 1] not in sb:
            mult += 1
        
        sb.discard(B[i])
        res = res * mult % mod
    
    print(res)

for testcase in range(II()):
    solve(testcase)
