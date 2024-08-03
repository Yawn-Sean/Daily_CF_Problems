# Submission link: https://codeforces.com/contest/645/submission/257673867
def main():
    n, m = MII()
    edges = []
    for _ in range(m):
        u, v = GMI()
        edges.append((u, v))

    l, r = 1, m
    while l <= r:
        mid = (l + r) // 2
        path = [[] for _ in range(n)]
        indegs = [0] * n
        for i in range(mid):
            u, v = edges[i]
            path[u].append(v)
            indegs[v] += 1
        
        stack = [i for i in range(n) if indegs[i] == 0]
        f = 1
        while stack:
            if len(stack) > 1:
                f = 0
                break
            u = stack.pop()
            for v in path[u]:
                indegs[v] -= 1
                if indegs[v] == 0:
                    stack.append(v)
        
        if f: r = mid - 1
        else: l = mid + 1

    print(l if l <= m else -1)