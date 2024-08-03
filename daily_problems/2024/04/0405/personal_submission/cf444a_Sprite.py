n, m = map(int, input().split())
nodes = list(map(int, input().split()))
ans = 0
for _ in range(m):
    a, b, c = map(int, input().split())
    ans = max(ans, (nodes[a-1] + nodes[b-1]) / c)
print(ans)
