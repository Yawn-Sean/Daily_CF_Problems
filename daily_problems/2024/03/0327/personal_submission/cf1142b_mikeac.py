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
    n, m, q = mint()
    p = ints()
    nums = ints()

    nxt = [0] * n
    for i, x in enumerate(p):
        nxt[x - 1] = p[(i + 1) % n] - 1
    
    pos = [m] * n
    nxt_pos = [m] * m
    for i in range(m - 1, -1, -1):
        nxt_pos[i] = pos[nxt[nums[i] - 1]]
        pos[nums[i] - 1] = i
    
    last = list(range(m))
    n -= 1
    for k in range(n.bit_length()):
        if (n >> k) & 1:
            last = [nxt_pos[x] if x < m else m for x in last]
        nxt_pos = [nxt_pos[x] if x < m else m for x in nxt_pos]

    for i in range(m - 1, 0, -1):
        if last[i - 1] > last[i]:
            last[i - 1] = last[i]

    ans = []
    for _ in range(q):
        l, r = mint()
        ans.append(1 if last[l - 1] < r else 0)

    print(*ans, sep='')

solve()
