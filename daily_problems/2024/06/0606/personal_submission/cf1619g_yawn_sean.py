# Submission link: https://codeforces.com/contest/1619/submission/264331915
def main():
    I()
    n, k = MII()
    xs = []
    ys = []
    ts = []
    
    dx = defaultdict(list)
    dy = defaultdict(list)
    
    for i in range(n):
        x, y, timer = MII()
        xs.append(x)
        ys.append(y)
        ts.append(timer)
        
        dx[x ^ rnd].append(i)
        dy[y ^ rnd].append(i)
    
    union = UnionFind(n)
    
    for x in dx:
        dx[x].sort(key=lambda i: ys[i])
        for i in range(len(dx[x]) - 1):
            if ys[dx[x][i+1]] - ys[dx[x][i]] <= k:
                union.merge(dx[x][i], dx[x][i+1])
    
    for y in dy:
        dy[y].sort(key=lambda i: xs[i])
        for i in range(len(dy[y]) - 1):
            if xs[dy[y][i+1]] - xs[dy[y][i]] <= k:
                union.merge(dy[y][i], dy[y][i+1])
    
    timers = Counter()
    for i in range(n):
        p = union.find(i)
        if p not in timers or ts[i] < timers[p]:
            timers[p] = ts[i]
    
    nums = sorted(timers.values())
    k = len(nums)
    ans = k - 1
    
    for i in range(k):
        ans = min(ans, max(nums[i], k - 2 - i))
    return ans