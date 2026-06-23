# Submission link: https://codeforces.com/gym/106575/submission/379754111
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, ca, cb = MII()
        v1 = LII()
        v2 = LII()
        
        p1 = [0] * n
        p2 = [0] * n
        
        for i in range(n):
            p1[(v1[i] - 1) // 2] = i
            p2[(v2[i] - 1) // 2] = i
        
        ans = 10 ** 18
        cur = n
        
        for i in range(n):
            cur = fmin(cur, p1[i])
            ans = fmin(ans, cur * ca + p2[i] * cb)
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))