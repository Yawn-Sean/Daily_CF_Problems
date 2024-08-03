n, m = [int(x) for x in input().split()]
V = [int(v) for v in input().split()]
E = [[int(e) for e in input().split()] for _ in range(m)]
ans = 0
for u, v, w in E:
    ans = max(ans, float(V[u - 1] + V[v - 1]) / float(w))
print(ans)
