# Submission link: https://codeforces.com/gym/106094/submission/355969089
def main(): 
    M = 2 * 10 ** 5
    pr = list(range(M + 1))
    
    for i in range(2, M + 1):
        if pr[i] == i:
            for j in range(i, M + 1, i):
                pr[j] = i
    
    t = II()
    outs = []
    
    for _ in range(t):
        x, k = MII()
        
        cnt = []
        while x > 1:
            p = pr[x]
            c = 0
            while x % p == 0:
                x //= p
                c += 1
            cnt.append(c)
    
        ans = 0
        cur = 2
        v = 1
        while True:
            tmp = 0
            for i in range(len(cnt)):
                val = (cnt[i] + cur - 1) // cur
                tmp += val * cur - cnt[i]
                cnt[i] = val * cur
            
            if tmp > k: break
            
            ans = v
            
            k -= tmp
            cur *= 2
            v += 1
    
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))