n, k = MII()

g = [[] for _ in range(n)]
deg = [0] * n

for _ in range(n - 1):
    u, v = GMI()
    g[u].append(v)
    g[v].append(u)
    deg[u] += 1
    deg[v] += 1

vis = [False] * n
st = deque()
for i in range(n):
    if deg[i] == 1:
        st.append(i)
        vis[i] = True

cnt = 1
while cnt < k and st:
    s = set()
    for _ in range(len(st)):
        u = st.popleft()
        tmpu = 0
        
        for v in g[u]:
            if not vis[v]:
                tmpu += 1
                if deg[v] < 4:
                    print("No")
                    exit()
                else:
                    s.add(v)
        if tmpu == 0:
            print("No")
            exit()

    for v in s:
        vis[v] = True
        st.append(v)
    cnt += 1

s = set()
for _ in range(len(st)):
    u = st.popleft()
    tmpu = 0
    for v in g[u]:
        if not vis[v]:
            tmpu += 1
            s.add(v)
    if tmpu == 0:
        print("No")
        exit()

if len(s) == 1 and deg[list(s)[0]] >= 3 and cnt == k:
    print("Yes")
else:
    print("No")
