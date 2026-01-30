# Submission link: https://codeforces.com/gym/104408/submission/360730079
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        n, m = MII()
        cnt = [0] * m
        
        for _ in range(n):
            s = I()
            
            if int(s[m - 1]):
                cnt[m - 1] += 1
            
            for i in range(m - 1):
                if s[i] != s[i + 1]:
                    cnt[i] += 1
        
        ans = 0
        for i in range(m):
            ans += fmin(cnt[i], n - cnt[i])
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))