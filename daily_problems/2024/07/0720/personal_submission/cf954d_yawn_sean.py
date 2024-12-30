# Submission Link: https://codeforces.com/contest/954/submission/271451023
def main():
    n, m, s, t = MII()
    s -= 1
    t -= 1

    path = [[] for _ in range(n)]
    for _ in range(m):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    dis1 = [-1] * n
    dis1[s] = 0

    queue = [0] * n
    queue[0] = s

    l, r = 0, 1
    while l < r:
        u = queue[l]
        l += 1
        for v in path[u]:
            if dis1[v] == -1:
                dis1[v] = dis1[u] + 1
                queue[r] = v
                r += 1

    dis2 = [-1] * n
    dis2[t] = 0

    queue = [0] * n
    queue[0] = t

    l, r = 0, 1
    while l < r:
        u = queue[l]
        l += 1
        for v in path[u]:
            if dis2[v] == -1:
                dis2[v] = dis2[u] + 1
                queue[r] = v
                r += 1

    target = dis1[t]
    ans = 0
    for i in range(n):
        for j in range(i):
            if min(dis1[i] + dis2[j], dis2[i] + dis1[j]) + 1 >= target:
                ans += 1

    print(ans - m)