
def main():
    n = int(input())
    g = [[] for _ in range(n)]
    h = [1] * n
    mod = 998244353
    for i in range(2, n):
        h[i] = i * h[i-1] % mod
    for _ in range(n - 1):
        u,v = map(int,input().split())
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)
        
    ans = n
    vis = [False] * n
    st = [0]
    while st:
        u = st.pop()
        vis[u] = True
        ans = ans * h[len(g[u])] % mod
        for v in g[u]:
            if not vis[v]:
                st.append(v)
    
    print(ans)
main()