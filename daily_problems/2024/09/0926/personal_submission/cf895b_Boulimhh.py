"""
思路：找到a[l] 和 a[r] 范围内正好有 k 个数可以整除 x

将数组排序， 固定左边， 查找右边的范围， 右边在数组的范围大小即为满足题意的下标对(l, r)

二分更快， 直接二分。

"""
#python代码：
n, x, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
res = 0
for i in range(n):
    r = (a[i] - 1) // x + k
    res += bisect_left(a, (r + 1) * x) - bisect_left(a, max(a[i], r * x))
print(res)
