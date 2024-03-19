
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

tcn = I()
for _tcn_ in range(tcn):
    x, y, p, q = MI()


    def check(mid):
        return x <= p * mid and y <= q * mid and q * mid - y >= p * mid - x


    L, R = 1, 1 << 32
    ans = -1
    while L <= R:
        mid = (L + R) // 2
        if check(mid):
            ans = q * mid - y
            R = mid - 1
        else:
            L = mid + 1
    print(ans)