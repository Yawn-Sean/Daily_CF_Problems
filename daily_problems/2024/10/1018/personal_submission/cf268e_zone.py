n = II() 
ls, ps = [], [] 

for _ in range(n):
    l, p = MII() 
    ls.append(l)
    ps.append(p)

def cmp(i, j):
    va = (100 - ps[j]) * ps[i] * ls[i]
    vb = (100 - ps[i]) * ps[j] * ls[j]
    if va < vb: 
        return 1 
    if vb < va: 
        return -1 
    return 0

idx = sorted(range(n), key=cmp_to_key(cmp))
cur = ans = 0 

for i in idx: 
    ans += cur * (100 - ps[i]) + ls[i] * 10000 
    cur += ls[i] * ps[i]

print(ans / 10000)
