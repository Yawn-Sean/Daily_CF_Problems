# Submission link: https://codeforces.com/contest/813/submission/315775071
def main():
    n, x = MII()
    x -= 1

    path = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = GMI()
        path[u].append(v)
        path[v].append(u)

    def dis(u):
        ans = [-1] * n
        ans[u] = 0
        que = [u]
        for u in que:
            for v in path[u]:
                if ans[v] == -1:
                    ans[v] = ans[u] + 1
                    que.append(v)
        return ans

    dis0 = dis(0)
    disx = dis(x)

    print(max(dis0[i] for i in range(n) if disx[i] < dis0[i]) * 2)