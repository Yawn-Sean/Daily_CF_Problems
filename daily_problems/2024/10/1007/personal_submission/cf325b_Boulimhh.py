"""
思路：看到 n 的范围这么大， 一眼二分。

但是没想到推导公式，得出二分的变量。 所以看了🐏的代码
"""
#python代码：
n = int(input())
f = 1
for i in range(60):
    r = n + 1
    l = -1
    while l < r:
        mid = l + r >> 1 
        ans = mid * (mid - 1) // 2 + mid * (pow(2, i) - 1)
        if ans >= n:
            r = mid
        else:
            l = mid + 1
    if l % 2 and l * (pow(2, i) - 1 + l // 2) == n:
        print(pow(2, i) * l)
        f = 0
if f:
    print(-1)
