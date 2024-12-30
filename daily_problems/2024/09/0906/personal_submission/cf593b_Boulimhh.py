"""
思路：由于是判断区间内是否有交点， 可以先算出来直线在区间端点的值并排序。

这样就可以将对直线交点的判断转化为对点的处理。

一开始的想法是二重循环， 暴力判断每对点， 必tle。

但是没必要，只需要判断相邻的排序点就可以了。

"""
#python代码：
y = []
n = int(input())
x1, x2 = map(int, input().split())
for _ in range(n):
    k, b = map(int, input().split())
    y.append([k * x1 + b, k * x2 + b])
y.sort()
#  转化为对点的判断， 是否有ya1 < ya2, yb1 > yb2。
for i in range(n - 1):
    if y[i + 1][1]< y[i][1]:
        print("YES")
        exit()
else:
    print("NO") 
