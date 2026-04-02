# Submission link: https://codeforces.com/gym/105971/submission/369348607
def main(): 
    t = II()
    outs = []
    
    mod = 10 ** 9 + 7
    
    for _ in range(t):
        n, m, k = MII()
        xs = []
        ys = []
        
        for _ in range(k + 1):
            x, y = GMI()
            xs.append(x)
            ys.append(y)
        
        flg = True
        for i in range(k):
            if abs(xs[i + 1] - xs[i]) + abs(ys[i + 1] - ys[i]) != 2:
                flg = False
        
        if not flg: outs.append(0)
        else:
            uf = UnionFind(n * m)
            edge_cnt = [0] * (n * m)
            self_cycle = [0] * (n * m)
            
            def f(x, y):
                return x * m + y
            
            for i in range(k):
                x1, y1 = xs[i], ys[i]
                x2, y2 = xs[i + 1], ys[i + 1]
    
                if x1 == x2 or y1 == y2:
                    msk = f((x1 + x2) // 2, (y1 + y2) // 2)
                    edge_cnt[msk] += 1
                    self_cycle[msk] = 1
                else:
                    msk1 = f(x1, y2)
                    msk2 = f(x2, y1)
                    uf.merge(msk1, msk2)
                    edge_cnt[msk1] += 1
            
            for i in range(n * m):
                if uf.find(i) != i:
                    edge_cnt[uf.find(i)] += edge_cnt[i]
                    self_cycle[uf.find(i)] |= self_cycle[i]
            
            ans = 1
            for i in range(n * m):
                if uf.find(i) == i:
                    if edge_cnt[i] > uf.getSize(i):
                        ans = 0
                    elif edge_cnt[i] == uf.getSize(i):
                        if not self_cycle[i]:
                            ans = ans * 2 % mod
                    else:
                        ans = ans * uf.getSize(i) % mod
            
            outs.append(ans)
    
    print('\n'.join(map(str, outs)))