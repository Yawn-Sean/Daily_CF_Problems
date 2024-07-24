import sys
input = lambda: sys.stdin.readline().strip()

MOD = 998244353
A = [1]
for i in range(1, 200000):
    A.append(i * A[i - 1] % MOD)

n = int(input())
g = [[] for _ in range(n)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)

res = n
st = [0]
vis = [False] * n
while st:
    for _ in range(len(st)):
        u = st.pop()
        vis[u] = True
        res = res * A[len(g[u])] % MOD
        for v in g[u]:
            if not vis[v]:
                st.append(v)
print(res)
        
