import sys
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())

tcn = I()
for _tcn_ in range(tcn):
    n, k = MI()
    s = list(input()) + ['#', '#', '#', '#', '#', '#', '#', '#']
    n += 8
    R = [[0] * n for _ in range(3)]
    G = [[0] * n for _ in range(3)]
    B = [[0] * n for _ in range(3)]
    for i in range(n):
        if s[i] == 'R':
            R[i % 3][i] = 1
        if s[i] == 'G':
            G[i % 3][i] = 1
        if s[i] == 'B':
            B[i % 3][i] = 1
    AR = [list(accumulate(R[i], initial=0)) for i in range(3)]
    AG = [list(accumulate(G[i], initial=0)) for i in range(3)]
    AB = [list(accumulate(B[i], initial=0)) for i in range(3)]
    ans = k
    for i in range(n - k - 3):
        # 'RGB'
        i1, i2, i3 = i, i + 1, i + 2
        tmp1 = k - (AR[i1 % 3][i + k] - AR[i1 % 3][i1] + AG[i2 % 3][i + k] - AG[i2 % 3][i2] +
                    AB[i3 % 3][i + k] - AB[i3 % 3][i3])
        ans = min(ans, tmp1)
        # GBR
        i1, i2, i3 = i, i + 1, i + 2
        tmp2 = k - (AG[i1 % 3][i + k] - AG[i1 % 3][i1] + AB[i2 % 3][i + k] - AB[i2 % 3][i2] +
                    AR[i3 % 3][i + k] - AR[i3 % 3][i3])
        ans = min(ans, tmp2)

        # BRG
        i1, i2, i3 = i, i + 1, i + 2
        tmp3 = k - (AB[i1 % 3][i + k] - AB[i1 % 3][i1] + AR[i2 % 3][i + k] - AR[i2 % 3][i2] +
                    AG[i3 % 3][i + k] - AG[i3 % 3][i3])
        ans = min(ans, tmp3)
    print(ans)
