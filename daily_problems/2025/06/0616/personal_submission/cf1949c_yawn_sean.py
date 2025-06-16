# Submission link: https://codeforces.com/contest/1949/submission/324579151
def main():
    n = II()
    path = [[] for _ in range(n)]

    degs = [0] * n

    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)
        degs[u] += 1
        degs[v] += 1

    val = [1] * n

    pq = [val[i] * n + i for i in range(n) if degs[i] == 1]
    cnt = 0

    for _ in range(n - 1):
        x, u = divmod(heappop(pq), n)
        cnt += 1
        for v in path[u]:
            if val[v]:
                if val[v] >= val[u]:
                    val[v] += val[u]
                    val[u] = 0
                    degs[v] -= 1
                    
                    if degs[v] == 1:
                        heappush(pq, val[v] * n + v)
                else:
                    exit(print('NO'))

    print('YES')