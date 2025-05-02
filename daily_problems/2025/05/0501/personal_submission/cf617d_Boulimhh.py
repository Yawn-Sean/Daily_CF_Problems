"""
输出为 2 的情况没有考虑清楚

在两个点平行于坐标轴形成的线段的上侧或者下侧， 有一点， 也可以打印答案为 2

一开始看到这种情况很懵， 看了羊神题解才反应过来

"""
# python代码：
x, y = [], []
for _ in range(3):
    x1, y1 = map(int, input().split())
    x.append(x1)
    y.append(y1)
    
def check(i, j, k):
    if x[i] == x[j] and not min(y[i], y[j]) < y[k] < max(y[i], y[j]): return True
    if y[i] == y[j] and not min(x[i], x[j]) < x[k] < max(x[i], x[j]): return True
    return False
    
if x[0] == x[1] == x[2] or y[0] == y[1] == y[2]:
    print(1)
elif check(0, 1, 2) or check(1, 2, 0) or check(0, 2, 1):
    print(2)
else: print(3)
