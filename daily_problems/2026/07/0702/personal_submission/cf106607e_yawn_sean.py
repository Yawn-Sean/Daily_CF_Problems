# Submission link: https://codeforces.com/gym/106607/submission/380887530
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n = II()
        ans = n * (n - 1) // 2
        
        c1 = 0
        c2 = 0
        
        for _ in range(n):
            x, y = MII()
            if x < y:
                ans -= c1
                c1 += 1
            elif x > y:
                ans -= c2
                c2 += 1
        
        outs.append(ans)
    
    print('\n'.join(map(str, outs)))