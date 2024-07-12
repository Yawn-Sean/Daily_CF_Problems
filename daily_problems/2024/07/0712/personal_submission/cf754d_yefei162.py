import sys
from heapq import heappop, heappush

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
TI = lambda: tuple(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353
inf = 10 ** 15

tcn = 1
for _tcn_ in range(tcn):
    n, k = MI()
    segments = [LI() + [i] for i in range(n)]
    segments.sort(key=lambda x: (x[0], -x[1]))

    in_seq = [-1] * n
    out_seq = [n] * n

    h = []
    ans = 0
    ts = 0

    for i in range(k):
        heappush(h, (segments[i][1], segments[i][0], segments[i][2]))
        in_seq[segments[i][2]] = i

    L = segments[k - 1][0]
    R = h[0][0]
    if R - L + 1 > ans:
        ans = R - L + 1
        ts = 0

    for i in range(k, n):
        L = segments[i][0]
        heappush(h, (segments[i][1], segments[i][0], segments[i][2]))
        in_seq[segments[i][2]] = i

        x, y, i1 = heappop(h)
        out_seq[i1] = i

        R = h[0][0]
        if R - L + 1 > ans:
            ans = R - L + 1
            ts = i - k + 1

    print(ans)
    rets = []
    for i in range(n):
        if in_seq[i] <= ts + k - 1 < out_seq[i]:
            rets.append(i)
    print(' '.join(str(x + 1) for x in rets))
