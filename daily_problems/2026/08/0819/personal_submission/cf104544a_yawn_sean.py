# Submission link: https://codeforces.com/gym/104544/submission/387533752
def main():
    n, x = MII()
    
    factors = []
    
    for i in range(1, 100000):
        if x // i < i: break
        if x % i == 0:
            factors.append(i)
            if x // i != i:
                factors.append(x // i)
    
    factors.sort()
    
    k = len(factors)
    d = {v: i for i, v in enumerate(factors)}
    
    cnt = [0] * k
    
    for v in MII():
        cnt[d[math.gcd(v, x)]] += 1
    
    gcds = [[0] * k for _ in range(k)]
    
    for i in range(k):
        for j in range(k):
            gcds[i][j] = math.gcd(factors[i], factors[j])
    
    dp = [inf] * k
    dp[0] = 0
    
    for i in range(k):
        for _ in range(cnt[i]):
            ndp = dp[:]
            flg = False
            
            for j in range(k):
                nj = d[factors[j] * gcds[d[x // factors[j]]][i]]
                if ndp[nj] > dp[j] + 1:
                    ndp[nj] = dp[j] + 1
                    flg = True
            
            if not flg:
                break
            
            dp = ndp
    
    print(dp[-1] if dp[-1] < inf else -1)