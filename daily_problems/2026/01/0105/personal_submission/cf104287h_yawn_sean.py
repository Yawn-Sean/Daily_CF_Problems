# Submission link: https://codeforces.com/gym/104287/submission/356401231
def main(): 
    t = II()
    outs = []
    
    M = 10 ** 5
    mod = 10 ** 9 + 7
    pw2 = [1] * (M + 1)
    
    for i in range(M):
        pw2[i + 1] = pw2[i] * 2 % mod
    
    rev2 = (mod + 1) // 2
    
    for _ in range(t):
        d = II()
        ans = 0
        
        edges = 1
        total = pw2[d] - 1
        cur = total
        
        for i in range(d - 1):
            cur = (cur - 1) * rev2 % mod
            edges = edges * 2 % mod
            
            ans = (ans + cur * (total - cur) % mod * edges % mod) % mod
        
        outs.append(ans * 2 % mod)
    
    print('\n'.join(map(str, outs)))