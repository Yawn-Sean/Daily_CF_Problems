n = int(input().strip())
nxt_tag = [[] for _ in range(n + 1)]
vis = [False] * (n + 1)
next_of_one = [-1, -1]
for i in range(n):
    a, b = map(int, input().strip().split())
    nxt_tag[a].append(b)
    nxt_tag[b].append(a)
    if i == 0:
        next_of_one[0]=a
        next_of_one[1]=b
ans = [-1] * n
ans[0] = 1
vis[1] = True
for i in range(1,n):
    pre = ans[i - 1]
    ans[i] = nxt_tag[pre][1] if not vis[nxt_tag[pre][1]] else nxt_tag[pre][0]
    vis[ans[i]] = True
if ans[1] not in next_of_one:
    print(" ".join(map(str, ans[::-1])))
else:
    print(" ".join(map(str, ans)))
