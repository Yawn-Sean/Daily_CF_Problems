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
    n, l, r, s = mint()
    m = r - l + 1
    if s < (1 + m) * m // 2 or s > (n + n - m + 1) * m // 2:
        print(-1)
        return
    ans = list(range(1, m + 1))
    cur = (1 + m) * m // 2
    i = m - 1
    k = n - m
    while cur < s:
        k = min(k, s - cur)
        ans[i] += k
        s -= k
        i -= 1
    used = set(ans)
    for i in range(1, n + 1):
        if i not in used:
            ans.append(i)
    
    if l > 1:
        ans = ans[1 - l:] + ans[:n - l + 1]
    print(*ans)


for _ in range(int(input())):
    solve()
