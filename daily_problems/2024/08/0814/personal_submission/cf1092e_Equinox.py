import sys

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
I = lambda: input()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
P = 1_000_000_007

sys.stdin = open('in.txt', 'r')

def solve():
    n, m = MII()
    adj = [[] for _ in range(n)]

    for _ in range(m):
        u, v = MII()
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)

    d0 = [-1] * n
    d = [[] for _ in range(n)]
    ma = -1
    mag, g = 1_000_000_007, -1

    def dfs0(u: int, p: int) -> None:
        d0[u] = 0
        for v in adj[u]:
            if v == p: continue
            dfs0(v, u)
            d0[u] = fmax(d0[u], d0[v] + 1)

    def dfs1(u: int, p: int) -> None:
        nonlocal g, mag, ma
        fi = se = -1
        for v in adj[u]:
            if d0[v] > fi:
                se, fi = fi, d0[v]
            elif d0[v] > se:
                se = d0[v]

        ma = fmax(ma, fi + se + 2)
        if fi + 1 < mag:
            mag = fi + 1
            g = u

        for v in adj[u]:
            if v == p: continue
            d0[u] = 1 + (se if d0[v] == fi else fi)
            dfs1(v, u)

    for u in range(n):
        if d0[u] == -1:
            dfs0(u, -1)
            ma = -1
            mag, g = 1_000_000_007, -1
            dfs1(u, -1)
            d[ma].append(g)

    ans = []
    cur, ma = -1, 0
    for i in range(n - 1, -1, -1):
        for u in d[i]:
            if cur == -1:
                cur = u
                ma = i
            else:
                ans.append(f'{cur + 1} {u + 1}')
                ma = fmax(ma, ((i + 1) // 2 + (ma + 1) // 2 + 1))

    print(ma)
    print('\n'.join(ans))




if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()