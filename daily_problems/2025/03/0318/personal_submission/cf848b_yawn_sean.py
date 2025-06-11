# Submission link: https://codeforces.com/contest/848/submission/311183466
def main():
    n, w, h = MII()
    gs = []
    ps = []
    ts = []

    for _ in range(n):
        g, p, t = MII()
        gs.append(g)
        ps.append(p)
        ts.append(t)

    d = defaultdict(list)
    ans = [''] * n

    for i in range(n):
        d[ps[i] - ts[i]].append(i)

    for v in d.values():
        v1 = []
        v2 = []
        
        for i in v:
            if gs[i] == 1:
                v1.append(i)
            else:
                v2.append(i)
        
        v1.sort(key=lambda x: ps[x])
        v2.sort(key=lambda x: -ps[x])
        
        for i in range(len(v)):
            start = v2[i] if i < len(v2) else v1[i - len(v2)]
            end = v1[i] if i < len(v1) else v2[i - len(v1)]
            
            ans[start] = f'{ps[end]} {h}' if gs[end] == 1 else f'{w} {ps[end]}'

    print('\n'.join(ans))