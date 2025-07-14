def main():
    for n in range(13, 16, 2):
        p1, p2 = [0 for _ in range(n)], [i for i in range(n)]
        vis1, vis2 = [False for _ in range(n)], [False for _ in range(2 * n)]
        res = 0
        def dfs(u):
            nonlocal vis1, p1, p2, res
            if u == n:
                p3 = [(p1[i] + p2[i]) % n for i in range(n)]
                p3.sort()
                ok = True
                for i in range(n):
                    if p3[i] != i:
                        ok = False
                if ok:
                    res += 1
                return

            for i in range(n):
                if not vis1[i] and not vis2[i + u]:
                    vis1[i] = True
                    vis2[i + u] = True
                    p1[u] = i
                    dfs(u + 1)
                    vis1[i] = False
                    vis2[i + u] = False
        dfs(0)
        for i in range(1, n + 1):
            res *= i
        print(n, res)

res = [0, 1, 0, 18, 0, 1800, 0, 670320, 0, 734832000, 0, 1510890796800, 0, 6416116740633600, 0, 150347555, 0]
n = int(input())
mod = int(1e9 + 7)
print(res[n] % mod)
