# Submission link: https://codeforces.com/contest/1835/submission/315897186
def main():
    t = II()
    outs = []

    for _ in range(t):
        a, b, c, k = MII()
        
        la = 10 ** (a - 1)
        ra = 10 ** a - 1
        lb = 10 ** (b - 1)
        rb = 10 ** b - 1
        lc = 10 ** (c - 1)
        rc = 10 ** c - 1
        
        flg = False
        
        for x in range(la, ra + 1):
            l = fmax(lb, lc - x)
            r = fmin(rb, rc - x)
            
            if l <= r:
                diff = r - l + 1
                if diff >= k:
                    flg = True
                    y = l + k - 1
                    outs.append(f'{x} + {y} = {x + y}')
                    break
                else:
                    k -= diff
        
        if not flg:
            outs.append('-1')

    print('\n'.join(outs))