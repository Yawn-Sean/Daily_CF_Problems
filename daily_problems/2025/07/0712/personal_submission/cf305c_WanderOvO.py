"""
先对 a[i] 做一个进位操作，从而看目前最高位是啥，以及缺哪些位
把缺的位补上就好了
"""
from collections import defaultdict

n = int(input())
a = list(map(int, input().split()))

max_bit = 0
cnt = defaultdict(int)
for i in range(n):
    cnt[a[i]] += 1
new_cnt = defaultdict(int)
for key, value in cnt.items():
    cur_key = key
    cur_value = value
    while new_cnt[cur_key] + cur_value > 1:
        carry = (new_cnt[cur_key] + cur_value) // 2
        new_cnt[cur_key] = (new_cnt[cur_key] + cur_value) % 2
        cur_key += 1
        cur_value = carry
    new_cnt[cur_key] += cur_value
    if new_cnt[cur_key] > 0:
        max_bit = max(max_bit, cur_key)
res = max_bit + 1
for key, value in new_cnt.items():
    if value > 0:
        res -= 1
print(res)
