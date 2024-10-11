import sys
from sortedcontainers import SortedList
from bisect import bisect_left
from bisect import bisect_right
from string import ascii_uppercase

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
P = 10**9 + 7

sys.stdin = open('in.txt', 'r')



class Fenwick:
    __slots__ = 'n', 'tr'
    def __init__(self, n: int):
        self.n = n
        self.tr = [0] * (n + 1)
    def add(self, x: int, k: int) -> None:
        n = self.n
        tr = self.tr
        while x <= n:
            tr[x] += k
            x += x & -x
    def query(self, x: int) -> int:
        res = 0
        tr = self.tr
        while x:
            res += tr[x]
            x &= x - 1
        return res
    def init(self):
        self.tr = [0] * (self.n + 1)

def solve():
    n, k = MII()
    a = [II() for _ in range(n)]

    f = [1] * n
    tr = Fenwick(n)

    for k in range(k):
        tr.init()
        for i in range(n):
            tr.add(a[i], f[i])
            f[i] = tr.query(a[i] - 1)
    print(sum(f))

if __name__ == "__main__":
    solve()


