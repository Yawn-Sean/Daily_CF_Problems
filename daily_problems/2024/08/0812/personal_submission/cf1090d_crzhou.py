from collections import defaultdict

n, m = map(int, input().split())

a = [0] * n
e = defaultdict(list)

for i in range(m):
    u, v = map(int, input().split())
    u -= 1  
    v -= 1  
    e[u].append(v)
    e[v].append(u)

if m == n * (n - 1) // 2:
    print("NO")
else:
    vis = [0] * n
    pa = pb = -1
    now = 0
    for i in range(n):
        if len(e[i]) == n - 1:
            continue
        for j in e[i]:
            vis[j] = 1
        for j in range(n):
            if i != j and not vis[j]:
                pa = i
                pb = j
                now = 1
                break
        if now:
            break

    for i in range(n):
        if i != pa and i != pb:
            a[i] = now
            now += 1
    a[pa] = n - 1
    a[pb] = n

    print("YES")
    print(' '.join(map(str, a)))
    
    a[pa] = min(a[pa], n - 1)
    a[pb] = min(a[pb], n - 1)
    
    print(' '.join(map(str, a)))
