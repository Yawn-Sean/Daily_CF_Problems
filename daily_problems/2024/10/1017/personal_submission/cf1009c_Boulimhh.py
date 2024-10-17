"""
思路： 直接看每组操作对总和的影响， 再除以 n 即可。

如果乘的是正数， 需要最大化， 那么 i 取 0 或 n - 1 效益增加最大。

如果是负数， 那么 i 取中间效益损失最小。

"""
#python代码：
n, m = map(int,input().split())

ans = 0
t = sum(abs(i - n // 2) for i in range(n))
s = (n - 1) * n // 2
for _ in range(m):
    a, b = map(int,input().split())
    ans += a * n 
    if b >= 0:
        ans += b * s 
    else:
        ans += b * t
print(ans / n)
