def solve(testcase):
    n = II()
    adj = defaultdict(list)
    fa = [-1 for _ in range(n)]
    vis = [False for _ in range(n)]
    mp = defaultdict(lambda : defaultdict(int))
    order = []
    
    for i in range(1, n):
        u, v = MI()
        u -= 1
        v -= 1
        
        adj[u].append(v)
        adj[v].append(u)
        
        mp[u][v] = mp[v][u] = i
    
    q = deque()
    q.append((0, -1))
    while q:
        cur, father = q.popleft()
        order.append(cur)
        for o in adj[cur]:
            if o != father:
                q.append((o, cur))
                fa[o] = cur
    
    res = []
    # print('order', order)
    
    for o in reversed(order):

        if vis[o]:
            pass
        else:
            father = fa[o]
            if father == -1:
                print(-1)
                return
            
            if vis[father]:
                print(-1)
                return
            else:
                grand = fa[father]
                availables = []
                for node in adj[father]:
                    if node != grand:
                        if not vis[node]:
                            availables.append(node)
                
                # print(o, availables)
                
                if len(availables) > 2:
                    print(-1)
                    return
                elif len(availables) == 2:
                    for node in availables:
                        vis[node] = True
                    vis[father] = True
                    if grand != -1:
                        res.append((father, grand))
                else:
                    if grand == -1:
                        print(-1)
                        return
                    else:
                        gf = fa[grand]
                        if vis[grand]:
                            print(-1)
                            return
                        # print(node, father, grand)
                        vis[o] = vis[father] = vis[grand] = True
                        if gf != -1:
                            res.append((grand, gf))
        
        # print('o', o, vis)
    # print(res)
    
    if sum(vis) == n:
        print(len(res))
        print(*[mp[l][r] for l, r in res])
    else:
        print(-1)
            
                    

for testcase in range(II()):
    solve(testcase)
