# Submission link: https://codeforces.com/contest/1510/submission/327162434
def main():
    t = II()
    outs = []

    for _ in range(t):
        n, k = MII()
        parent = [-1] + LGMI()
        path = [[] for _ in range(n)]
        
        depth = [0] * n
        for i in range(1, n):
            depth[i] = depth[parent[i]] + 1
            path[parent[i]].append(i)
        
        cur = 0
        for i in range(n):
            if depth[i] < k and depth[i] > depth[cur]:
                cur = i
        
        cnt = depth[cur] + 1
        ans = []
        vis = [0] * n
        
        def dfs(i):
            nonlocal cnt
            vis[i] = 1
            ans.append(i)
            for j in path[i]:
                if not vis[j] and cnt < k:
                    cnt += 1
                    dfs(j)
                    ans.append(i)
        
        while cur >= 0:
            dfs(cur)
            cur = parent[cur]
        
        ans.reverse()
        outs.append(str(len(ans) - 1))
        outs.append(' '.join(str(x + 1) for x in ans))

    print('\n'.join(outs))