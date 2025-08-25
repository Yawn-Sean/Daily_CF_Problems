# Submission link: https://codeforces.com/contest/15/submission/335234588
def main():
    t = II()
    outs = []
    
    for _ in range(t):
        n, m, x1, y1, x2, y2 = MII()
        
        if x1 > x2: x1, x2 = x2, x1
        if y1 > y2: y1, y2 = y2, y1
        
        a = x1 + n - x2
        b = y1 + m - y2
        outs.append(n * m - 2 * a * b + fmax(0, a * 2 - n) * fmax(0, b * 2 - m))
    
    print('\n'.join(map(str, outs)))