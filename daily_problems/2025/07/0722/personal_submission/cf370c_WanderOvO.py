"""
每个人只换一只手就行，钦定只换左手
考虑每种颜色出现次数，如果有绝对众数，则其他颜色的都和绝对众数交换
如果没有绝对众数，则可以考虑两两相消，也可以考虑组成一个环相消
最后都可以转化成 2 元环或者 3 元环，因为更大的环都可以被这两个表示
绝对众数只需要用 2 元环消，无绝对众数考虑用 3 元环消

换一种思考方式，假设出现次数最多的数有 cnt 个
把所有一样的数聚集在一起，复制一份，循环右移 cnt 位
如果 2 * cnt <= n，则此时每对数肯定都是不一样的
如果 2 * cnt > n，则至少有 2 * cnt - n 对数是一样的
"""
from collections import defaultdict

n, m = map(int, input().split())
a = list(map(int, input().split()))
cnt = defaultdict(int)
for i in range(n):
    cnt[a[i]] += 1

left = []
max_cnt = 0
for key, value in cnt.items():
    max_cnt = max(max_cnt, value)
    for i in range(value):
        left.append(key)

right = [left[(i + max_cnt) % n] for i in range(n)]
print(n - max(0, 2 * max_cnt - n))
for i in range(n):
    print(f'{left[i]} {right[i]}')
