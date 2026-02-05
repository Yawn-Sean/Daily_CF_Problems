# Submission link: https://codeforces.com/gym/106351/submission/361539985
def main(): 
    M = 100000
    factors = [[] for _ in range(M + 1)]
    
    for i in range(1, M + 1):
        for j in range(i, M + 1, i):
            factors[j].append(i)
    
    n, x, y = MII()
    nums = LII()
    
    cnt = [0] * (M + 1)
    for v in nums:
        cnt[v] += 1
    
    ans = 0
    
    for i in range(x, y + 1):
        ans += cnt[i] * (cnt[i] - 1) // 2
        
        l = len(factors[i])
        for j in range(l):
            for k in range(j):
                g = math.gcd(factors[i][j], factors[i][k])
                if g >= x and factors[i][j] * factors[i][k] // g == i:
                    ans += cnt[factors[i][j]] * cnt[factors[i][k]]
    
    print(ans)