n = int(input())
a = [0] + list(map(int, input().split()))
b = [Node(0, 0)] + [Node(i, a[i]) for i in range(1, n+1)]

for i in range(1, n+1):
    add(i, 1)

b.sort(key=lambda x: x.v)

del_ = [False] * (n+1)
cur = 1
ans = 0

for i in range(1, n+1):
    if not del_[i]:
        del_[i] = True
        add(i, -1)
    while cur <= n and b[cur].v < i:
        if not del_[b[cur].id]:
            del_[b[cur].id] = True
            add(b[cur].id, -1)
        cur += 1
    ans += ask(min(n, a[i]))
