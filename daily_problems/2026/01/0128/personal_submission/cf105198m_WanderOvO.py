"""
算出横纵坐标差的绝对值 dx 和 dy
不妨 dx <= dy
如果 k * (dx + 1) >= dy，则答案就是 dx + dy
否则，先用 dx 去每 k 个隔开一次 dy，这样算一下 d = dy - k * (dx + 1)
算一下 (d + k - 1) / k，如果这个东西是奇数，还得再 + 1
这就是最终的次数
"""

import sys

input = lambda: sys.stdin.readline().rstrip()

def solve():
    sx, sy, tx, ty, k = map(int, input().split())
    dx, dy = abs(tx - sx), abs(ty - sy)
    
    if dx > dy:
        dx, dy = dy, dx

    ans = dx + dy
    
    if (dx + 1) * k >= dy:
        print(ans)
        return
    
    d = dy - k * (dx + 1)
    another = (d + k - 1) // k

    if another % 2 != 0:
        another += 1
    ans += another
    
    print(ans)

T = 1
T = int(input())
while T > 0:
    T -= 1
    solve()
