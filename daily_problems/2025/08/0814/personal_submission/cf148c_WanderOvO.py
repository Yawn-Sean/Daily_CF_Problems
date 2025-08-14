"""
直接构造一个单调递增序列，等次数够了之后剩下的都是 1
如果有过多的 wow，会导致序列爆炸增长，爆范围
b <= 15，而 2^15 = 32768 < 50000，所以数据范围保证了不会爆范围
先处理 wow，后边处理 oh
注意 2 比 1 大，所以是 wow 而不是 oh
没有 wow 时，需要至少凑两个 1，才能 oh
"""

n, a, b = map(int, input().split())
res = []
s = 0
left = n
for i in range(b + 1):
    res.append(s + 1)
    if s + 1 > 50000:
        print(-1)
        exit(0)
    s += s + 1
left -= (b + 1)
if len(res) > 1:
    last = res[-1]
else:
    last = 1
    if left > 0:
        res.append(last)
        left -= 1
    else:
        if a > 0:
            print(-1)
            exit(0)
for i in range(a):
    res.append(last + 1)
    if last + 1 > 50000:
        print(-1)
        exit(0)
    last += 1
left -= a
if left < 0:
    print(-1)
    exit(0)
for i in range(left):
    res.append(1)
assert len(res) == n
print(*res)
