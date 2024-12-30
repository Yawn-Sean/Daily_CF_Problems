"""
首先只需要在 k+1 个元素上作查询即可。
考虑一个长为 k+1 的递增数组，第 i 次查询输入的是除第 i 个元素外的所有元素。则所有的查询结果总共只有两种：原数组第 m+1 大元素，共出现 m 次；原数组第 m 大元素，共出现 k-m+1 次。因此所有查询结果的较大值的出现次数即为所求。在这样的方案下，元素出现位置都是不必要的。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
mii = lambda: map(int, input().split())

_, k = mii()
mx0, mx1 = -1, -1
c0, c1 = 0, 0
for i in range(1, k+2):
    print('?', *(j for j in range(1, k+2) if j != i), flush=True)
    _, x = mii()
    if mx0 == -1 or x == mx0:
        mx0 = x
        c0 += 1
    else:
        mx1 = x
        c1 += 1
    if mx0 < mx1:
        mx0, mx1 = mx1, mx0
        c0, c1 = c1, c0

print('!', c0)
