"""
每层用掉的木棍数是 3k + 2，其中 k >= 0
搭建一个 cnt 层的房子，需要 O(cnt^2) 级别的木棍，因此只需要判断 1e6 以内的高度即可
枚举高度 h，第一层至少需要 3(h - 1) + 2 个木棍，第 2 层至少需要 3(h - 2) + 2 个木棍
第 h 层至少需要 2 个木棍，求和就是 2h + 3 * (h - 1) * h / 2 根木棍
假设还剩 cnt 根木棍：
- cnt % 3 == 0，则可以都放到第一层
- cnt % 3 != 0，废了，放哪里都不可能
"""

n = int(input())
max_h = int(1e6)
res = 0
for h in range(1, max_h):
    cnt = 2 * h + 3 * (h - 1) * h // 2
    if cnt > n:
        break
    cnt = n - cnt
    if cnt % 3 == 0:
        res += 1
print(res)
