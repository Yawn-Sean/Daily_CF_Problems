# Submission link: https://codeforces.com/contest/208/submission/319449013
def main():
    n, m = MII()
    path = [[] for _ in range(n)]

    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    dis1 = [-1] * n
    dis1[0] = 0
    que = [0]

    for u in que:
        for v in path[u]:
            if dis1[v] == -1:
                dis1[v] = dis1[u] + 1
                que.append(v)


    dp1 = [0] * n
    dp1[0] = 1

    for u in que:
        for v in path[u]:
            if dis1[v] + 1 == dis1[u]:
                dp1[u] += dp1[v]

    disn = [-1] * n
    disn[n - 1] = 0
    que = [n - 1]

    for u in que:
        for v in path[u]:
            if disn[v] == -1:
                disn[v] = disn[u] + 1
                que.append(v)

    dpn = [0] * n
    dpn[n - 1] = 1

    for u in que:
        for v in path[u]:
            if disn[v] + 1 == disn[u]:
                dpn[u] += dpn[v]

    ans = dp1[n - 1]

    for i in range(1, n - 1):
        res = 0
        for j1 in path[i]:
            for j2 in path[i]:
                if dis1[j1] + disn[j2] + 2 == dis1[n - 1]:
                    res += dp1[j1] * dpn[j2]
        ans = fmax(ans, res * 2)

    print(ans / dp1[n - 1])