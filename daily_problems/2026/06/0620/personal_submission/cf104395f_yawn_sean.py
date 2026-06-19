# Submission link: https://codeforces.com/gym/104395/submission/379492945
def main():
    n, m = MII()
    uf = UnionFind(n)
    
    mod = 10 ** 9 + 7
    f = Factorial(n, mod)
    
    ans = 0
    
    for _ in range(m):
        u, v = GMI()
        if not uf.merge(u, v):
            ans += 1
    
    for i in range(1, n - m + 1):
        ans += f.inv(i)
        ans %= mod
    
    print(ans)