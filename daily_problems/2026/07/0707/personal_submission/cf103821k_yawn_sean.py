# Submission link: https://codeforces.com/gym/103821/submission/381391487
def main():
    t = II()
    outs = []
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        n, m = MII()
        
        tmp1 = [0] * (m + 1)
        tmp2 = [0] * (m + 1)
        
        for _ in range(n):
            l, r = MII()
            tmp1[l] += m + 1 - r
            tmp2[r] += l
        
        ans = 0
        total = 0
        
        for i in range(m, 0, -1):
            ans = (ans + tmp2[i] * total) % mod
            total = (total + tmp1[i]) % mod
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))