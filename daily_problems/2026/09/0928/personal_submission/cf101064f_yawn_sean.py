# Submission link: https://codeforces.com/gym/101064/submission/392286222
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, idx = MII()
        ans = 0
        
        while True:
            if idx % 2 == 1:
                ans += idx // 2 + 1
                break
            
            ans += n // 2
            idx //= 2
            if n % 2:
                idx += 1
            n -= n // 2
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))