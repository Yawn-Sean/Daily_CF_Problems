'''
https://codeforces.com/contest/243/submission/271009104
243B
2024/7/17 Y2
2000
graph, tree, set operations
'''

n, m, h, t = map(int, input().split())
g = [set() for _ in range(n + 1)]
edges = []
cn = [0] * (n + 1)
for _ in range(m):
    a, b = map(int, input().split())
    g[a].add(b)
    g[b].add(a)
    cn[a] += 1
    cn[b] += 1
    edges.append((a, b))
ok = False
x, y = h, t
if x < y: 
    x, y = y, x
for a, b in edges:
    ss = g[a] & g[b]
    ca, cb = cn[a] - len(ss) - 1, cn[b] - len(ss) - 1
    if (ca > cb) != (h > t):
        a, b = b, a
        ca, cb = cb, ca
    if ca + len(ss) >= h:
        cb1 = cb + len(ss) if ca >= h else cb + (len(ss) - (h - ca))
        if cb1 >= t:
            ok = True
            lss = list(ss)
            print("YES")
            print(a, b)

            g[a] -= ss
            g[a].remove(b)
            g[b] -= ss
            g[b].remove(a)
            ans_a = list(g[a])
            if ca >= h:
                ans_a = ans_a[:h]
            else:
                ans_a += lss[:h-ca]
            ans_b = list(g[b])
            if cb >= t:
                ans_b = ans_b[:t]
            else:
                ans_b += lss[-(t-cb):]
            print(*ans_a)
            print(*ans_b)
            break
if not ok:
    print("NO")


