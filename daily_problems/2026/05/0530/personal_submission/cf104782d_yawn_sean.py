# Submission link: https://codeforces.com/gym/104782/submission/376546158
def main():
    n = II()
    v1 = LII()
    v2 = LII()
    
    vals = [(v2[i] - v1[i], v2[i]) for i in range(n)]
    
    def f(a, b):
        xa, ya = a
        xb, yb = b
        
        x = xa + xb
        y = fmax(ya + xb, yb)
        
        return (x, y)
    
    inf = 10 ** 15
    seg = SegTree(f, (0, -inf), vals)
    
    q = II()
    outs = []
    
    for _ in range(q):
        l, r = GMI()
        outs.append(seg.prod(l, r + 1)[1])
    
    print('\n'.join(map(str, outs)))