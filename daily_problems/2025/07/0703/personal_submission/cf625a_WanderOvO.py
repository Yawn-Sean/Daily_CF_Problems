"""
如果 b - c >= a，则完全没必要买 b
如果 b - c < a，则优先买 b
假设能买 cnt 个 b，则应该满足 (b - c) * (cnt - 1) + b <= n
=> cnt <= (n - b) / (b - c) + 1
取最大的 cnt，则后边剩下的钱只能买 a 了
似乎会爆范围，用 py 实现
"""

n = int(input())
a = int(input())
b = int(input())
c = int(input())

res = 0
if b - c > a:
    res = n // a
else:
    if n >= b:
        cnt = (n - b) // (b - c) + 1
        n -= cnt * (b - c)
        res += cnt
    res += n // a
print(res)
