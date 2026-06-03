# Submission link: https://codeforces.com/gym/106523/submission/376857372
def main():
    n = II()
    nums = LGMI()
    
    mod = 998244353
    pw2 = [1] * (n + 1)
    
    for i in range(n):
        pw2[i + 1] = pw2[i] * 2 % mod
    
    ans = 0
    uf = UnionFind(n + 1)
    
    for i in range(n):
        uf.init()
    
        for j in range(n):
            uf.merge(j, fmin(nums[j] + i, n))
        
        cur = 0
        
        for j in range(n):
            if uf.find(j) == j and uf.find(j) != uf.find(n):
                cur += 1
        
        ans += pw2[cur] - 1
        ans %= mod
    
    print(ans)