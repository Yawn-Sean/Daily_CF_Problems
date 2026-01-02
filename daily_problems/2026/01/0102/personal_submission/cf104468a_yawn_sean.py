# Submission link: https://codeforces.com/gym/104468/submission/356114719
def main(): 
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        pos = [[] for _ in range(2 * n + 1)]
        
        for i in range(n):
            x, y = MII()
            pos[x].append((i, 0))
            pos[y].append((i, 1))
        
        flg = True
        uf = UnionFind(2 * n)
        
        for i in range(2 * n + 1):
            if len(pos[i]) > 2:
                flg = False
            
            elif len(pos[i]) == 2:
                idx1, f1 = pos[i][0]
                idx2, f2 = pos[i][1]
                if f1 != f2:
                    uf.merge(idx1, idx2)
                    uf.merge(idx1 + n, idx2 + n)
                else:
                    uf.merge(idx1 + n, idx2)
                    uf.merge(idx1, idx2 + n)
        
        for i in range(n):
            if uf.find(i) == uf.find(i + n):
                flg = False
        
        if not flg: outs.append(-1)
        else:
            cnt = [0] * n
            cnt1 = [0] * n
            
            for i in range(2 * n):
                if uf.find(i) < n:
                    cnt[uf.find(i)] += 1
                    if i < n:
                        cnt1[uf.find(i)] += 1
            
            ans = 0
            for i in range(n):
                ans += fmin(cnt1[i], cnt[i] - cnt1[i])
            
            outs.append(ans)

    print('\n'.join(map(str, outs)))