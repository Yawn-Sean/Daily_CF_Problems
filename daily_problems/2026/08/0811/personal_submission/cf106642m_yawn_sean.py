# Submission link: https://codeforces.com/gym/106642/submission/386425690
def main():
    t = II()
    outs = []
    
    rnd = random.getrandbits(30)
    
    for _ in range(t):
        n = II()
        v1 = LII()
        v2 = LII()
        
        ans = 0
        
        cnt = Counter()
        
        for i in range(n):
            ans += cnt[(v1[i] - v2[i]) ^ rnd]
            cnt[(v1[i] - v2[i]) ^ rnd] += 1
        
        cnt = Counter()
        
        for i in range(n):
            ans += cnt[(v1[i] + v2[i]) ^ rnd]
            cnt[(v1[i] + v2[i]) ^ rnd] += 1
        
        cnt = Counter()
        
        for i in range(n):
            ans -= cnt[(v1[i], v2[i])]
            cnt[(v1[i], v2[i])] += 1
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))