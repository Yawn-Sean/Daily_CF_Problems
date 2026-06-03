import sys
from array import array
from itertools import accumulate

input = lambda: sys.stdin.readline().rstrip()


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

prea = list(accumulate(a, initial=0))
preb = list(accumulate(b, initial=0))

M = 17
to = [array('i', [0] * (n + 1)) for _ in range(M)]

prec = [0] + [b[i] - a[i + 1] for i in range(n - 1)]
for i in range(1, n):
    prec[i] += prec[i - 1]
stk = []
for i, x in enumerate(prec):
    while stk and x < prec[stk[-1]]:
        to[0][stk.pop() + 1] = i + 1
    stk.append(i)

for p in range(1, M):
    for i in range(1, n + 1):
        to[p][i] = to[p - 1][to[p - 1][i]]


def solve() -> str:
    l, r = map(int, input().split())
    x = l
    for p in range(M - 1, -1, -1):
        y = to[p][x]
        if y != 0 and y <= r:
            x = y
    return str(preb[r] - preb[x - 1] - (prea[r] - prea[x]))


print('\n'.join(solve() for _ in range(int(input()))))


"""
考虑 Bob 是怎么移动的, Bob 会重复进行以下过程:
- 等待 Alice 完成一个 game
- 不停的进行 game

显然不停的进行 game 是非常方便进行处理的, 只需要一个前缀和即可
对于等待 Alice 的过程, 我们考虑用倍增来解决

考虑如何寻找下一次 Bob 进行等待的位置
假设当前 Bob 在等待 i-th game, 下一次在等待 j-th game
那一定有:
sum(b[i:k]) >= sum(a[i+1:k+1]) for k in range(i+1,j)
sum(b[i:j]) < sum(a[i+1:j+1])
我们可以定义数组 c[i] := b[i]-a[i+1]
这样我们寻找的就:
sum(c[i:k]) >= 0 for k in range(i+1,j)
sum(c[i:j]) < 0
从 c 求得前缀和数组 prec (这里的 prec 没有 initial, 代码里的有), 就变成了:
prec[i-1] <= prec[k] for k in range(i,j-1)
prec[i-1] > prec[j-1]
维护单调栈即可

然后就做完啦啦啦啦
"""
