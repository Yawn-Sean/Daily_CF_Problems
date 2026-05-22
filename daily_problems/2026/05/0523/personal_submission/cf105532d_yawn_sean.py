# Submission link: https://codeforces.com/gym/105532/submission/375635531
def main():
    n = II()
    xs = []
    ys = []
    
    for _ in range(n):
        x, y = MII()
        
        if x > y: x, y = y, x
        
        xs.append(x)
        ys.append(y)
    
    ans = 0
    cur = 0
    
    for i in sorted(range(n), key=lambda x: -ys[x]):
        cur += xs[i]
        ans = fmax(ans, fmin(cur, ys[i]))
    
    print(ans)