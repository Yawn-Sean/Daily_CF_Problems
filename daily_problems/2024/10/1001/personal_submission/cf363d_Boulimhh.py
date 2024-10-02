"""
思路：贪心的想法是让有钱人买贵的，把便宜的留给钱少的， 这样就可以尽可能的选择多的车。

由于数据范围有点大， 考虑二分， 计算在有限资金内可以搞到的车的数量 m。

至于个人支出， 就让车的价格排序， 找前 m 个车的总价格，减去现有的钱就ok。
"""
#python代码：

n, m, a = map(int,input().split())
b = list(map(int,input().split()))
p = list(map(int,input().split()))

p.sort()
b.sort()
l,r = 0, min(n, m)
while l < r:
    mid = l + r + 1 >> 1
    res = 0
    for i in range(mid):
        res += max(0, p[i] - b[n - mid + i])
        if res > a:
            r = mid - 1
            break
    else:
        l = mid
print(r, max(0, sum(p[:r]) - a))
