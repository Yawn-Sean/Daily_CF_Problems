from queue import deque
def main():
    n,m = map(int,input().split())
    g = [[] for _ in range(n)]
    
    for _ in range(m):
        a,b = map(int,input().split())
        a -= 1
        b -= 1
        g[a].append(b)
        g[b].append(a)
    ans = []
    for i in range(n):
        if len(g[i]) >= 4:
            vis = [-1] * n
            fa = [-1] * n
            # 标记染色颜色
            vis[i] = i
            q =  deque([x for x in g[i]])
            for u in q:
                vis[u] = u
                fa[u] = i
            while q:
                u = q.popleft()
                for v in g[u]:
                    if vis[v] == -1:
                        vis[v] = vis[u]
                        fa[v] = u
                        q.append(v)
            for u in range(n):
                for v in g[u]:
                    # 颜色不一样的边相连，可以缩小循环或者不缩小形成鱼骨
                    if u != i and v != i and vis[u] != vis[v] and vis[v] != -1 and vis[u] != -1  :
                        ans.append((u,v))
                        while u != i:
                            vis[u] = -1
                            ans.append((u,fa[u]))
                            u = fa[u]
                        while v != i:
                            vis[v] = -1
                            ans.append((v,fa[v]))
                            v = fa[v]
                        cnt = 0
                        for x in g[i]:
                            if vis[x] != -1:
                                cnt += 1
                                ans.append((i,x))
                                if cnt == 2:
                                    break
                        break
                if len(ans):
                    break
            if len(ans):
                break
    if len(ans):
        print('YES')
        print(len(ans))
        for x,y in ans:
            print(x+1,y+1)
    else:
        print('NO')



            
    


T = int(input())
for _ in range(T):
    main()