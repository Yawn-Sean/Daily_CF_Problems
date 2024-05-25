def solve():
    n = int(input())
    adj = [[int(x) - 1 for x in input().split()] for _ in range(n)]
    for i in range(2):
        ans = [0, adj[0][i]]
        for _ in range(n):
            u = ans[-2]
            ok = False
            nxt = -1
            for j in range(2):
                if adj[u][j] == ans[-1]:
                    ok = True 
                else:
                    nxt = adj[u][j]
            if ok: ans.append(nxt)
            else: break 
        if len(ans) == n + 2: 
            print(' '.join(str(x + 1) for x in ans[:n]))
            break 
solve()
