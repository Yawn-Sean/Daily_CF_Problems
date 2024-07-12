import sys

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
II = lambda: int(input())
P = 998244353


'''
    拼积木
    每次两块首尾拼一块就行
    直接模拟
'''
def solve():
    n = II()
    p = [-1] * n
    ed = list(range(n))
    nxt = [-1] * n

    def find(x: int) -> int:
        if p[x] < 0:
            return x
        p[x] = find(p[x])
        return p[x]

    def merge(x: int, y: int) -> None:
        px, py = find(x), find(y)
        if px == py:
            return
        if p[px] > p[py]:
            px, py = py, px
        p[px] += p[py]
        p[py] = px
        nxt[ed[px]] = py
        ed[px] = ed[py]

    for i in range(n - 1):
        a, b = MII()
        merge(a - 1, b - 1)

    res = [find(0)]
    for i in range(n - 1):
        res.append(nxt[res[-1]])

    print(' '.join(str(x + 1) for x in res))


if __name__ == "__main__":
    solve()


