# Submission link: https://codeforces.com/gym/102861/submission/338620052
def main():
    n, m = MII()
    XorBase.n = n + 1
    base = XorBase()
    
    neighbor = [0] * n
    cnt = [0] * n
    
    for _ in range(m):
        u, v = GMI()
        neighbor[u] |= 1 << v + 1
        neighbor[v] |= 1 << u + 1
        cnt[u] ^= 1
        cnt[v] ^= 1
    
    for i in range(n):
        if cnt[i]: neighbor[i] |= 1 << i + 1
        else: neighbor[i] |= 1
    
    for x in neighbor:
        base.add(x)
    
    print('N' if base.check(1) else 'Y')