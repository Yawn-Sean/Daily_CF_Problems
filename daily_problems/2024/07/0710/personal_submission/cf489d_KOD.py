times = 1  # 0有t, 1无t
if not times:
    times = ix()
for _ in range(times):
    n, s = il()
    edges = [[] for i in range(n+1)]
    for i in range(s):
        a, b = il()
        edges[a] += b,
    cnt = [0] * (n+1)
    ans = 0
    for i in range(n+1):
        for j in edges[i]:
            for k in edges[j]:
                cnt[k] += 1
        for p in range(n+1):
            if p != i:
                ans += cnt[p]*(cnt[p]-1)//2
            cnt[p] = 0
    print(ans)
