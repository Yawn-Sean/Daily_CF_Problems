t = II()

for _ in range(t):
    n = II()
    k = n
    a = LII()
    ans = [0] * n
    vis = [0] * n
    tmp = []

    for i in range(n):
        if vis[a[i] - 1] or a[i] == i + 1:
            
            k -= 1
            continue
        ans[i] = a[i]
        vis[a[i] - 1] = 1

    for i in range(n):
        if not vis[i]:
            tmp.append(i + 1)

    for i in range(n):
        if not ans[i]:
            ans[i] = tmp.pop()

    for i in range(n):
        if ans[i] == i + 1:
            for j in range(n):
                if ans[j] == a[i]:
                    ans[j] = i + 1
                    break
            ans[i] = a[i]
            break

    print(k)
    print(' '.join(map(str, ans)))
