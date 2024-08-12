import sys

input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
LMI = lambda: list(map(int, input().split()))
LI = lambda: list(input())
II = lambda: int(input())
I = lambda: input()
fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y
P = 1_000_000_007

sys.stdin = open('in.txt', 'r')


class FenWick:
    __slots__ = 'n', 'tr'
    def __init__(self, n: int):
        self.n = n
        self.tr = [0] * (n + 1)

    def init(self, _init: list[int]) -> None:
        n = len(_init)
        self.n = n
        self.tr = [0] * (n + 1)
        for i in range(1, n + 1):
            self.tr[i] += _init[i - 1]
            self.tr[i + (i & -i)] += self.tr[i]

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
def solve():
    n = II()
    a = LMI()
    tr = FenWick(n)

    ans = [0] * (n - 1)
    id = list(range(n))
    id.sort(key=lambda x:a[x])
    for i in id:
        for k in range(1, n):
            L, R = k * i + 1, k * (i + 1) + 1
            if L >= n:
                break
            R = fmin(n, R)
            ans[k - 1] += tr.query(R) - tr.query(L)
        tr.add(i + 1,1)
    print(*ans)
    pass


if __name__ == "__main__":
    T = 1
    # T = II()
    for _ in range(T):
        solve()