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

mxn = 10 ** 7
factor = [1] * (mxn + 1)
d = [1] * (mxn + 1)
ans = [-1] * (mxn + 1)
def init():
    for i in range(2, mxn + 1):
        if factor[i] != 1:
            continue
        for j in range(i, mxn + 1, i):
            factor[j] = i
    for i in range(2, mxn + 1):
        s, p = 0, 1
        while i % p == 0:
            s += p
            p *= factor[i]
        p //= factor[i]
        d[i] = d[i // p] * s
    for i in range(1, mxn + 1):
        if d[i] <= mxn and ans[d[i]] == -1:
            ans[d[i]] = i

def solve() -> None:
    print(ans[sint()])

init()
for _ in range(sint()):
    solve()
