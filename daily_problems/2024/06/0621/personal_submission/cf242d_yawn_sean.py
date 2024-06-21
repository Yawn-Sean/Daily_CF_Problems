# Submission link: https://codeforces.com/contest/242/submission/266604673
def main():
    n, m = MII()
    path = [[] for _ in range(n)]

    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    vals = [0] * n
    target = LII()

    ans = []
    stack = [i for i in range(n) if target[i] == 0]

    while stack:
        u = stack.pop()
        ans.append(u)
        vals[u] += 1
        for v in path[u]:
            vals[v] += 1
            if vals[v] == target[v]:
                stack.append(v)

    print(len(ans))
    print(' '.join(str(x + 1) for x in ans))