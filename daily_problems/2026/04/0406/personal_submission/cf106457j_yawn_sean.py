# Submission link: https://codeforces.com/gym/106457/submission/369870898
def main(): 
    n, q = MII()
    
    ls = []
    rs = []
    seps = []
    
    for _ in range(n):
        l, r = MII()
        ls.append(l)
        rs.append(r)
        seps.append(l)
        seps.append(r + 1)
    
    seps.sort()
    
    k = len(seps)
    diff = [0] * k
    
    for i in range(n):
        diff[bisect.bisect_left(seps, ls[i])] += 1
        diff[bisect.bisect_left(seps, rs[i] + 1)] -= 1
    
    for i in range(1, k):
        diff[i] += diff[i - 1]
    
    acc = [0] * k
    for i in range(k - 1):
        acc[i + 1] = acc[i] + diff[i] * (seps[i + 1] - seps[i])
    
    queries = LII()
    outs = []
    
    for x in queries:
        x -= 1
        p = bisect.bisect_right(acc, x) - 1
        outs.append(seps[p] + (x - acc[p]) // diff[p])
    
    print('\n'.join(map(str, outs)))