# Submission link: https://codeforces.com/gym/106054/submission/381836911
def main():
    n, m = MII()
    
    vs1 = []
    cs1 = []
    vs2 = []
    cs2 = []
    
    d = {}
    
    for i in range(n + m):
        v1, c1, v2, c2 = LI()
        v1 = int(v1)
        v2 = int(v2)
        
        vs1.append(v1)
        cs1.append(c1)
        vs2.append(v2)
        cs2.append(c2)
        
        if c1 not in d: d[c1] = []
        if c2 not in d: d[c2] = []
        
        if c1 != c2:
            d[c1].append(i)
            d[c2].append(~i)
    
    k = n + m + 2
    
    def f(x, f1):
        return x * 2 + f1
    
    def op(u1, u2):
        first1, second1 = u1
        xfirst1, yfirst1 = divmod(first1, 2)
        xsecond1, ysecond1 = divmod(second1, 2)
    
        first2, second2 = u2
        xfirst2, yfirst2 = divmod(first2, 2)
        xsecond2, ysecond2 = divmod(second2, 2)
        
        if yfirst1 == 0:
            xfirst = xfirst1 + xfirst2
            yfirst = yfirst2
        else:
            xfirst = xfirst1 + xsecond2
            yfirst = ysecond2
        
        if ysecond1 == 0:
            xsecond = xsecond1 + xfirst2
            ysecond = yfirst2
        else:
            xsecond = xsecond1 + xsecond2
            ysecond = ysecond2
        
        return f(xfirst, yfirst), f(xsecond, ysecond)
    
    def e(): return f(0, 0), f(0, 1)
    
    def win(): return f(1, 0), f(1, 0)
    
    def lose(): return f(0, 1), f(0, 1)
    
    def draw(): return f(1, 0), f(0, 1)
    
    def check(idx):
        if cs1[idx] == cs2[idx]:
            return win() if vs1[idx] > vs2[idx] else lose()
        return draw()
    
    seg = SegTree(op, e(), [check(i) for i in range(n + m)])
    
    for x in d:
        for idx in d[x]:
            if idx >= 0: seg.set(idx, win())
            else: seg.set(~idx, lose())
        
        if seg.all_prod()[0] // 2 == n:
            print(x)
            break
        
        for idx in d[x]:
            if idx >= 0: seg.set(idx, draw())
            else: seg.set(~idx, draw())
    else:
        print('*')