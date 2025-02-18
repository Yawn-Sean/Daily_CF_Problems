"""
思路： 首先特判只有两个数的情况。

再分别取 最小的数 和其他数在一个 partition 中， 和不在一个 partition 中的两种情况。

取函数差值的最小值即可。

"""
#python代码：
n, h = map(int, input().split())
if n == 2:
    print(0)
    print(1, 1)
    exit()
a = list(map(int, input().split()))
t = a.index(min(a))
a.sort()

f1 = a[-1] + a[-2] - a[0] - a[1]
f2 = max(a[-1] + a[-2], a[-1] + a[0] + h) - min(a[0] + a[1] + h, a[1] + a[2])
print(min(f1, f2))
if f1 <= f2:
    for _ in range(n): print(2, end = ' ')
else:
    for i in range(n):
        print(2 if t != i else 1, end = ' ')
