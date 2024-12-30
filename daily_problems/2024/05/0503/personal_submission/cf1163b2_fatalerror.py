"""
参考 https://leetcode.cn/problems/remove-letter-to-equalize-frequency 。
用哈希表统计数字出现频率，再用另一个哈希表统计频率的频率。分情况讨论即可。
"""

import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

n = ii()
arr = lii()
ans = 0
cnt = {}
freq = {}
for i, x in enumerate(arr, 1):
    if x in cnt:
        freq[cnt[x]] -= 1
        if not freq[cnt[x]]:
            del freq[cnt[x]]
    cnt[x] = cnt.get(x, 0) + 1
    freq[cnt[x]] = freq.get(cnt[x], 0) + 1
    if len(freq) == 1:
        f, *_ = freq.keys()
        if f == 1 or freq[f] == 1:
            ans = i
    elif len(freq) == 2:
        f1, f2 = freq.keys()
        if f1 < f2: f1, f2 = f2, f1
        if (f1-1 == f2 and freq[f1] == 1) or (f2 == 1 and freq[f2] == 1):
            ans = i

print(ans)
