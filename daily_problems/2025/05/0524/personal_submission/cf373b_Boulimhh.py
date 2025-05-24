"""
根据给的样例先骗几分, 把输出为0的情况先搞掉

再二分一下, check 里把 l 分成不同长度的段来计算成本

由于计算的是满足情况的最大值, 所以写二分最大值的板子
"""


# python 代码
w, m, k = map(int, input().split())
if w < k or w // k < len(str(m)): 
    print(0)
    exit()

def check(l):
    cost, x = 0, m
    while l > 0:
        d = len(str(x))
        cnt = min(l, 10 ** d - x)
        cost += cnt * d
        x += cnt
        l -= cnt
    return cost <= w

w = w // k
l, r = 0, w + 1
while l < r:
    mid = l + r + 1 >> 1
    if check(mid): l = mid
    else: r = mid - 1

print(r)
