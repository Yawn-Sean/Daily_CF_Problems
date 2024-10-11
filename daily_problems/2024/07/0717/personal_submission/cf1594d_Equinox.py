import sys
from sortedcontainers import SortedList
from bisect import bisect_left
from bisect import bisect_right
from string import ascii_uppercase
from math import inf

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
P = 10**9 + 7

sys.stdin = open('in.txt', 'r')

def solve():
    n, m = MII()
    g = [[] for _ in range(n)]
    for _ in range(m):
        a, b, s = input().split()
        a, b = map(int, [a, b])
        a -= 1
        b -= 1
        w = 1 if s[0] == 'i' else 0
        g[a].append([b, w])
        g[b].append([a, w])

    color = [-1] * n
    cnt = [0, 0]
    def dfs(x: int, y: int) -> bool:
        stk = [x]
        color[x] = y
        cnt[y] += 1
        while stk:
            u = stk[-1]
            stk.pop()
            c = color[u]
            for v, w in g[u]:
                if ~color[v] and color[v] != c ^ w:
                    return  False
                elif color[v] == -1:
                    stk.append(v)
                    color[v] = c ^ w
                    cnt[c ^ w] += 1
        return True
    res = 0

    for i in range(n):
        if ~color[i]:
            continue
        cnt = [0, 0]
        if not dfs(i, 0):
            print(-1)
            return
        res += fmax(cnt[0], cnt[1])

    print(res)

if __name__ == "__main__":
    T = 1
    T = II()
    for _ in range(T):
        solve()