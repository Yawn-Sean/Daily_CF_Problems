# Submission Link: https://codeforces.com/contest/366/submission/267585570
def main():
    n, m = MII()
    path = [[] for _ in range(n)]

    tmp = []

    for _ in range(m):
        u, v, l, r = MII()
        u -= 1
        v -= 1
        tmp.append(l)
        path[u].append((v, l, r))
        path[v].append((u, l, r))

    fmin = lambda x, y: x if x < y else y

    ans = 0
    for left in tmp:
        max_r = [-1] * n
        max_r[0] = 10 ** 6
        
        hpq = [-max_r[0] * n]
        while hpq:
            d, u = divmod(heappop(hpq), n)
            d = -d
            if max_r[u] == d:
                for v, l, r in path[u]:
                    r = fmin(r, d)
                    if l <= left and r > max_r[v]:
                        max_r[v] = r
                        heappush(hpq, -max_r[v] * n + v)
        if max_r[-1] - left + 1 >= ans:
            ans = max_r[-1] - left + 1

    print(ans if ans else 'Nice work, Dima!')