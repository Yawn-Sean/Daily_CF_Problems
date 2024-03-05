import sys
from collections import defaultdict

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
    ys = defaultdict(list)
    xs = set()
    for _ in range(n):
        x, y = mint()
        ys[y].append(x)
        xs.add(x)
    dis = {x:i for i, x in enumerate(sorted(xs), 1)}
    tn = len(dis)
    bit = [0] * (tn + 1)

    def query(x: int) -> int:
        res = 0
        while x:
            res += bit[x]
            x &= x - 1
        return res

    def add(x: int, val: int):
        while x <= tn:
            bit[x] += val
            x += x & -x
    
    cnt = [0] * (tn + 1)
    ans = s = 0
    mn, mx = tn, 0
    for y in sorted(ys.keys(), reverse=True):
        ys[y].sort()
        pre = mn - 1
        for x in ys[y]:
            i = dis[x]
            if i > pre:
                v = query(i - 1) - query(pre)
                ans -= v * (v + 1) // 2
            pre = i
            if cnt[i] == 0:
                cnt[i] = 1
                s += 1
                add(i, 1)
        if mx > pre:
            v = query(mx) - query(pre)
            ans -= v * (v + 1) // 2
        ans += s * (s + 1) // 2
        mn = min(mn, dis[ys[y][0]])
        mx = max(mx, dis[ys[y][-1]])

    print(ans)

solve()
