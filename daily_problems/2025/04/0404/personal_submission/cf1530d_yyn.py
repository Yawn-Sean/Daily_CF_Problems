def yyn():
    n = II()
    a = LII()
    ans = [-1] * n
    v = defaultdict(int)
    d = deque()
    for i in range(n):
        if a[i] not in v:
            ans[i] = a[i]
            v[a[i]] = i

    for i in range(1,n + 1):
        if i not in v:
            d.append(i)

    for i in range(n):
        if ans[i] == -1:
            x = d.pop()
            while i + 1 == x:
                if not d:
                    ans[v[a[i]]] = x
                    x = a[i]
                    break
                d.append(x)
                x = d.popleft()
            ans[i] = x
    k = 0
    for i in range(n):
        if a[i] == ans[i]:
            k += 1
    print(k)
    print(*ans)

