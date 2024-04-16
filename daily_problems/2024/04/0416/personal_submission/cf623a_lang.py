n, m = I.mii()
g = [[1] * n for _ in range(n)]
for _ in range(m):
    u, v = I.mii()
    g[u-1][v-1] = 0
    g[v-1][u-1] = 0
for i in range(n):
    g[i][i] = 0
# print(g)

d = {1: 'a', 0: 'b', -1: 'c'}
ans = [2] * n
for i in range(n):
    flag = True
    for j in range(n):
        if i != j and g[i][j]:
            flag = False
            break
    if flag:
        ans[i] = 0

flag = True
for i in range(n):
    if ans[i] == 2:
        ans[i] = 1
        q = [i]
        while q and flag:
            u = q.pop()
            for v in range(n):
                if g[u][v]:
                    if ans[v] == ans[u]:
                        flag = False
                        break
                    if ans[v] == 2:
                        ans[v] = ans[u] * -1
                        q.append(v)

for i in range(n):
    for j in range(n):
        if g[i][j] == 0 and ans[i] * ans[j] == -1:
            flag=False
# print(ans)
if not flag:
    print("No")
else:
    print("Yes")
    ans = [d[i] for i in ans]
    print("".join(ans))
