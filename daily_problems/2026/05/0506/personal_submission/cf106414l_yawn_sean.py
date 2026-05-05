# Submission link: https://codeforces.com/gym/106414/submission/373552095
def main():
    t = II()
    outs = []
    
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        n = II()
        
        not_vis_prob = [1] * (n + 1)
        
        for _ in range(n):
            a, p, q = MII()
            not_vis_prob[a] = not_vis_prob[a] * (q - p) % mod * pow(q, -1, mod) % mod
        
        cur = 1
        ans = 0
        
        for x in not_vis_prob:
            cur = cur * (mod + 1 - x) % mod
            ans = (ans + cur) % mod
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))