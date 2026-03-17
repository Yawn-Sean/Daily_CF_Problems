# Submission link: https://codeforces.com/gym/106430/submission/367097557
def main(): 
    t = II()
    outs = []
    
    for _ in range(t):
        x, y = MII()
        
        if x == y: outs.append(0)
        elif x < y:
            ans = 0
            while x < y:
                x *= 2
                ans += 1
            outs.append(ans)
        else:
            if y <= 2: outs.append(-1)
            else:
                ans = 0
                while x > y:
                    x = 2 * x // 3 + 1
                    ans += 1
                outs.append(ans)
    
    print('\n'.join(map(str, outs)))