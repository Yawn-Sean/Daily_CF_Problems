# Submission link: https://codeforces.com/contest/1136/submission/300773889
def main():
    n, m = MII()
    perm = LGMI()

    path = [[] for _ in range(n)]

    for _ in range(m):
        u, v = GMI()
        path[u].append(v)

    vis = [0] * n
    vis[perm[n - 1]] = 1
    cnt = 1

    for i in range(n - 2, -1, -1):
        v = 0
        for j in path[perm[i]]:
            if vis[j]:
                v += 1
        if v < cnt:
            vis[perm[i]] = 1
            cnt += 1

    print(n - cnt)