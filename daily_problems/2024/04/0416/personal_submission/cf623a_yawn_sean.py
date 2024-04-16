# Submission link: https://codeforces.com/contest/623/submission/256853504
def main():
    n, m = MII()
    graph = [[1] * n for _ in range(n)]
    for i in range(n):
        graph[i][i] = 0

    for _ in range(m):
        u, v = GMI()
        graph[u][v] = graph[v][u] = 0

    ans = [1] * n

    for i in range(n):
        if ans[i] == 1 and sum(graph[i]) > 0:
            stack = [i]
            ans[i] = 0
            while stack:
                u = stack.pop()
                for v in range(n):
                    if graph[u][v] and ans[v] == 1:
                        ans[v] = ans[u] ^ 2
                        stack.append(v)

    for i in range(n):
        for j in range(i):
            if (ans[i] ^ ans[j] == 2) != graph[i][j]:
                print('No')
                return

    print('Yes')
    print(''.join(chr(ord('a') + x) for x in ans))