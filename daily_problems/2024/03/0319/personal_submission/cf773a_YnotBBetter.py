import math
import sys
input = lambda: sys.stdin.readline().strip()

# 在增加提交次数的过程中，y必定增大，x可能同步增大也可能不变，所以 y-x 必定是增加或不变的
# 假设最终的分数是 tx / ty，只要 ty - tx >= y - x，那么必定可以通过增加提交次数来得到目标比例
# 且 ty - tx 越大，需要补全的提交次数就越多
# 由于 p, q 的变化是成倍的，ty - tx 一定是 q - p 的倍数，为了得到最少的操作次数，要找到：
# 最小的 ty - tx 使得 ty - tx >= y - x 且 ty - tx 是 q - p 的倍数 且 ty >= y 且 tx >= x

t = int(input())
ans = []
for _ in range(t):
    x, y, p, q = map(int, input().split())
    if p == q:
        ans.append(math.ceil(y / q) * q - y if x == y else -1)
    elif p == 0 and x > 0:
        ans.append(-1)
    else:
        n = max(math.ceil((y - x) / (q - p)), math.ceil(y / q), math.ceil(x / p) if p > 0 else 0)
        ans.append(n * q - y)

print("\n".join(map(str, ans)))
