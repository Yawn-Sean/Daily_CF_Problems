import sys
input = lambda: sys.stdin.readline().strip()

mod = 10 ** 9 + 7
outs = []

def soviet():
    n = int(input())
    e = [[] for _ in range(n + 1)]
    e[0].append(1)  

    for i in range(1, n + 1):
        l, r = map(int, input().split())
        if l and r:  
            e[i].append(l)
            e[i].append(r)

    siz = [0] * (n + 1)
    stack = [(0, False)]  
    while stack:
        u, visited = stack.pop()
        if visited:
            siz[u] = 1
            for v in e[u]:
                siz[u] += siz[v]
        else:
            stack.append((u, True))
            for v in reversed(e[u]):
                stack.append((v, False))

    ans = [0] * (n + 1)
    ans[0] = 0
    stack = [0]
    while stack:
        u = stack.pop()
        for v in e[u]:
            ans[v] = ((siz[v] - 1) * 2 + 1 + ans[u]) % mod
            stack.append(v)
    outs.append(' '.join(str(ans[k]) for k in range(1, n + 1)))

t = int(input())
for _ in range(t):
    soviet()
print('\n'.join(outs))
