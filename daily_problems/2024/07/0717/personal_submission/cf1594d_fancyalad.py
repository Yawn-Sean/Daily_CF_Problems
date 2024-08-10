def solve():
    n, m = map(int, input().split())
    g = [set() for _ in range(n)]
    for _ in range(m):
        x, y, c = input().split()
        x = int(x) - 1; y = int(y) - 1
        if c[0] == 'i':
            g[x].add(~y)
            g[y].add(~x)
        else:
            g[x].add(y)
            g[y].add(x)
    
    flag = True
    ans = 0
    def chk():
        nonlocal flag, ans
        vis = [-1] * n
        for i, v in enumerate(vis):
            if v != -1:
                continue
            vis[i] = 0
            cnt = cnt1 = 0
            stk = [i]
            while stk:
                cnt += 1
                x = stk.pop()
                for y in g[x]:
                    if y >= 0:
                        if vis[y] == -1:
                            stk.append(y)
                            vis[y] = vis[x]
                            if vis[y] == 1: cnt1 += 1
                        elif vis[y] != vis[x]:
                            flag = False
                            return
                    else:
                        y = ~y
                        if vis[y] == -1:
                            stk.append(y)
                            vis[y] = vis[x] ^ 1
                            if vis[y] == 1: cnt1 += 1
                        elif vis[y] == vis[x]:
                            flag = False
                            return
            ans += max(cnt - cnt1, cnt1)

    chk()
    print(ans if flag else -1)    

check = int(input())
for _ in range(check):
    solve()
