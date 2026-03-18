# Submission link: https://codeforces.com/gym/105858/submission/367231660
def main(): 
    sa = [int(c) for c in I()]
    sb = [int(c) for c in I()]
    
    cnt = [0] * 10
    for x in sa: cnt[x] += 1
    for x in sb: cnt[x] += 1
    
    l = max(len(sa), len(sb))
    weights = [0] * l
    
    for i in range(len(sa)):
        weights[i] += 1
    
    for i in range(len(sb)):
        weights[i] += 1
    
    ans = 0
    cur = 9
    
    mod = 998244353
    
    for i in range(l - 1, -1, -1):
        ans = ans * 10 % mod
        
        for _ in range(weights[i]):
            while cnt[cur] == 0:
                cur -= 1
            ans = (ans + cur) % mod
            cnt[cur] -= 1
    
    print(ans)