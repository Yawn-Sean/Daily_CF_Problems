# Submission link: https://codeforces.com/problemset/submission/917/325939340#
def main():
    n, m = MII()
    path = [[] for _ in range(n)]
    indeg = [0] * n

    for _ in range(m):
        u, v, c = LI()
        u = int(u) - 1
        v = int(v) - 1
        c = ord(c) - ord('a')
        
        path[u].append(n * c + v)
        indeg[v] += 1

    stk = [i for i in range(n) if indeg[i] == 0]
    order = []

    while stk:
        u = stk.pop()
        order.append(u)
        for edge in path[u]:
            v = edge % n
            indeg[v] -= 1
            if indeg[v] == 0:
                stk.append(v)

    order.reverse()

    dp = [[-1] * (n * n) for _ in range(26)]
    for total in range(2 * n - 1):
        for i in range(fmax(total - n + 1, 0), n):
            u = order[i]
            v = order[total - i]
            for c in range(26):
                for edge in path[u]:
                    nc, nu = divmod(edge, n)
                    if nc >= c and dp[nc][v * n + nu] == 0:
                        dp[c][u * n + v] = 1
                        break
                else:
                    dp[c][u * n + v] = 0

    print('\n'.join(''.join('BA'[dp[0][i * n + j]] for j in range(n)) for i in range(n)))