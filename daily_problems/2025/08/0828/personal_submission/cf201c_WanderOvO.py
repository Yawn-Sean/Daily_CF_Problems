"""
只能走 1 次的边比较关键，因为走了之后就回不了头了
从 x 开始走，有怎样的走法？
- 先往左走，左边的部分走完之后回到 x，然后往右走（可以不回来）
- 只往左走，走完不回来了
- 先往右走，右边的部分走完之后回到 x，然后往左走（可以不回来）
- 只往右走，走完不回来了

不妨设从 x 向左走不回来/回来的最多走的步数是 dpl[0/1][x]
不妨设从 x 向右走不回来/回来的最多走的步数是 dpr[0/1][x]
则从 x 作为起点走，最多能走的步数很容易根据上面的分类计算出来

那么这些 dp 值如何求呢？
对于 dpl[1][i]，由于需要走回来，所以需要 a[i - 1] > 1 才行，否则直接赋值为 0
在 a[i - 1] > 1 的情况下，dpl[1][i] = dpl[1][i - 1] + a[i - 1] - (a[i - 1] % 2)，即 a[i - 1] 可以被挥霍偶数次

对于 dpl[0][i]，由于不用再走回 i 了，所以 a[i - 1] 只要 > 0 即可，这是天然满足的
然后还要分两种情况：
- 由 dpl[0][i - 1] 转移过来，即 i - 1 也不回了，这个时候需要先尽力消费掉 a[i - 1]，然后再继续走 i - 1
  贡献为 dpl[0][i - 1] + (a[i - 1] - (1 - a[i - 1] % 2))
- 由 dpl[1][i - 1] 转移过来，即我们还是要回 i - 1 的，只是不一定回 i 了，这个时候可以先把 i - 1 往左的走完，然后再挥霍 a[i - 1]
  贡献为 dpl[1][i - 1] + a[i - 1]，回了 i 其实也无所谓所以直接加 a[i - 1]

右边的分析也是类似的
"""
import sys

input = lambda: sys.stdin.readline().strip()
fmax = lambda a, b: a if a > b else b

n = int(input())
a = [0] + list(map(int, input().split()))

dpl = [[0 for _ in range(n + 1)] for _ in range(2)]
dpr = [[0 for _ in range(n + 1)] for _ in range(2)]

for i in range(2, n + 1):
    if a[i - 1] > 1:
        dpl[1][i] = dpl[1][i - 1] + a[i - 1] - (a[i - 1] % 2)
    dpl[0][i] = fmax(dpl[0][i - 1] + (a[i - 1] - (1 - a[i - 1] % 2)), dpl[1][i - 1] + a[i - 1])

for i in range(n - 1, 0, -1):
    if a[i] > 1:
        dpr[1][i] = dpr[1][i + 1] + a[i] - (a[i] % 2)
    dpr[0][i] = fmax(dpr[0][i + 1] + (a[i] - (1 - a[i] % 2)), dpr[1][i + 1] + a[i])

res = 0
for i in range(1, n + 1):
    res = max(res, dpl[0][i], dpl[1][i] + max(dpr[0][i], dpr[1][i]), dpr[0][i], dpr[1][i] + max(dpl[0][i], dpl[1][i]))
print(res)
