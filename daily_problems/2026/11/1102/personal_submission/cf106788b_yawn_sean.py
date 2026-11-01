# Submission link: https://codeforces.com/gym/106788/submission/396999858
def main(): 
    n, k = MII()
    
    pw = random.randint(10 ** 6, 2 * 10 ** 6)
    
    def gen():
        while True:
            x = random.getrandbits(40)
            if math.gcd(x, pw) == 1:
                return x
    
    rnd1 = gen()
    rnd2 = gen()
    
    pw1 = [1] * (k + 1)
    pw2 = [1] * (k + 1)
    
    for i in range(k):
        pw1[i + 1] = pw1[i] * pw % rnd1
        pw2[i + 1] = pw2[i] * pw % rnd2
    
    p = list(range(k))
    
    v1 = 0
    v2 = 0
    
    for i in range(k):
        v1 += pw1[i] * p[i]
        v2 += pw2[i] * p[i]
        
        v1 %= rnd1
        v2 %= rnd2
    
    cnt = Counter()
    cnt[(v1, v2)] = 1
    
    ans = 0
    
    for _ in range(n):
        x, y = GMI()
        
        v1 += (p[y] - p[x]) * (pw1[x] - pw1[y])
        v1 %= rnd1
        
        v2 += (p[y] - p[x]) * (pw2[x] - pw2[y])
        v2 %= rnd2
        
        p[x], p[y] = p[y], p[x]
        
        ans += cnt[(v1, v2)]
        cnt[(v1, v2)] += 1
    
    print(ans)