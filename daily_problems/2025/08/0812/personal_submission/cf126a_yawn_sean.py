# Submission link: https://codeforces.com/contest/126/submission/333546820
def main():
    t1, t2, x1, x2, t0 = MII()
    
    if t0 == t1 and t0 == t2:
        print(x1, x2)
    elif t0 == t1:
        print(x1, 0)
    elif t0 == t2:
        print(0, x2)
    else:
        ans1 = 0
        ans2 = x2
        
        for i in range(1, x1 + 1):
            t = ((t0 - t1) * i + t2 - t0 - 1) // (t2 - t0)
            if t > x2: continue
            if t * ans1 <= ans2 * i:
                ans1, ans2 = i, t
        
        print(ans1, ans2)