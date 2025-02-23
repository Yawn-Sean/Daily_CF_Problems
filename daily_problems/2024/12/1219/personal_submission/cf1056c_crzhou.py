n, m = MII()
ps = LII()
ps = sorted([(ps[i], i) for i in range(n * 2)], reverse=True)
enes = {}
vis = [0] * (2 * n)

for _ in range(m):
    a, b = GMI()
    enes[a] = b
    enes[b] = a
    
t = II()
pre = -1
if t == 2:
    pre = II() - 1
    vis[pre] = 1

for i in range(n):
    if pre in enes and not vis[enes[pre]]:
        cur = enes[pre]
        vis[cur] = 1
        print(cur + 1, flush=True)
    else:
        flg = False
        for j in range(n * 2):
            cur = ps[j][1]
            if cur in enes and not vis[cur]:
                flg = True
                vis[cur] = 1
                print(cur + 1, flush=True)
                break
                
        if not flg:
            for j in range(n * 2):
                if not vis[ps[j][1]]:
                    vis[ps[j][1]] = 1
                    print(ps[j][1] + 1, flush=True)
                    break
    if t == 2 and i == n - 1:
        break
    pre = II() - 1
    vis[pre] = 1
