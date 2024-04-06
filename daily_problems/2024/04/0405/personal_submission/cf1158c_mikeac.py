import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    n = sint()
    nxt = ints()
    for i in range(n):
        if nxt[i] == -1:
            nxt[i] = i + 1
        else:
            nxt[i] -= 1
    ans = [0] * n
    pos = [[] for _ in range(n + 1)]
    for i, c in enumerate(nxt):
        pos[c].append(i)
    x = n
    for i in range(n, -1, -1):
        for j in pos[i]:
            ans[j] = x
            x -= 1
    stk = [n]
    for i in range(n - 1, -1, -1):
        while len(stk) > 1 and ans[i] > ans[stk[-1]]:
            stk.pop()
        if nxt[i] != stk[-1]:
            print(-1)
            return
        stk.append(i)
    print(*ans)


for _ in range(int(input())):
    solve()
