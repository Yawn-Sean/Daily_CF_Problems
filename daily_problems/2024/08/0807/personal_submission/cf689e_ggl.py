mod = 10 ** 9 + 7
N = 2 * 10 ** 5 + 1
f , g = [1] * N, [1] * N
for i in range(1 , N):
    f[i] = f[i - 1] * i % mod
g[-1] = pow(f[-1] , mod - 2 , mod)
for i in range(N - 2, -1 , -1):
    g[i] = g[i + 1] * (i + 1) % mod
def comb(n , m):
    return f[n] * g[m] * g[n - m] % mod
def solve():        
    n , k = MII()
    seg = [tuple(MII()) for _ in range(n)]    
    diff = defaultdict(int)    
    for l , r in seg:
        diff[l] += 1
        diff[r + 1] -= 1
    keys = sorted(diff)
    keys.append(keys[-1] + 1)
    s = res = 0
    for cur, nxt in pairwise(keys):
        s += diff[cur]
        if s >= k:
            res += comb(s , k) * (nxt - cur)
            res %= mod        
    print(res)
