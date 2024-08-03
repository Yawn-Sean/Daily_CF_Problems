def main():
    n = int(input())
    g = [[] for _ in range(n)]
    z = []
    for _ in range(n - 1):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        z.append([a,b,c])
        g[a].append([b,c])
        g[b].append([a,c])
      
    size = [1] * n
    parent = [-1] * n
    # 不可以递归 会爆
    # def dfs(cur, par):
    #     parent[cur] = par
    #     for nxt, c in g[cur]:
    #         if nxt == par:
    #             continue
    #         size[cur] += dfs(nxt, cur)
    #     return size[cur]
    # dfs(0, -1)
    order = []
    stack = [0]
    while stack:
        cur = stack.pop()
        for nxt, _ in g[cur]:
            if nxt == parent[cur]:
                continue
            parent[nxt] = cur
            stack.append(nxt)
        order.append(cur)
    for cur in reversed(order):
        if cur:
            size[parent[cur]] += size[cur]
        

    w = dict()
    for i in range(1, n):
        c1 = size[i]
        c2 = n - size[i]
        w[(parent[i], i)] = c1 * c2 * (c2 - 1) // 2 + c2 * c1 * (c1 - 1) // 2
        w[(i,parent[i])] = c1 * c2 * (c2 - 1) // 2 + c2 * c1 * (c1 - 1) // 2
    ans = 0
    for a, b, c in z:
        ans += w[(a,b)] * c
        
    import math
    e = math.comb(n,3)

    res = []
    q = int(input())
    for _ in range(q):
        r,c = map(int, input().split())
        r -= 1
        ans += (c - z[r][-1]) * w[(z[r][0], z[r][1])]
        z[r][-1] = c
        res.append(ans / e * 2)
    print(*res,sep='\n')

main()