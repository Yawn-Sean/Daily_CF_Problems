n = ix()
v = set()
inf = 10 ** 9
def dfs(i, j, val):
    if val > inf: return
    v.add(val)
    dfs(i, j, val * 10 + i)
    dfs(i, j, val * 10 + j)

v.add(0)
for i in range(1, 10):
    for j in range(10):
        dfs(i, j, i)
ans = 0
for x in v:
    if n - x in v:
        ans += 1
print((ans + 1) // 2)
