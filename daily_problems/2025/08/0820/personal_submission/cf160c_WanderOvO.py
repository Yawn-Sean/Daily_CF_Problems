"""
把 a 排好序
第一维肯定是按照 a[0]...a[n - 1] 的顺序递增的
第二维不一定，因为有第一维平局的情况存在
假如有 a[i] = a[i + 1] < a[i + 2]
则正确的顺序应该是 (a[i], a[0]), (a[i + 1], a[0]), (a[i], a[1]), (a[i + 1], a[1])
把 a 转化为 (val, cnt) 的形式再排序，这样 val 就唯一了
枚举 (val, cnt)，假如当前的 k > cnt * n，则直接看下一个 (val, cnt)
否则，答案的第一维肯定是 val 了，现在只要考虑第二维是谁即可
枚举第二维的 (val2, cnt2) 对，cnt * cnt2
"""
from collections import defaultdict

n, k = map(int, input().split())
a = list(map(int, input().split()))

mp = defaultdict(int)
for i in range(n):
    mp[a[i]] += 1

pairs = []
for key, val in mp.items():
    pairs.append((key, val))

order = [i for i in range(len(pairs))]
order.sort(key=lambda x: pairs[x][0])

i = 0
while k > 0:
    id = order[i]
    if k > pairs[id][1] * n:
        k -= pairs[id][1] * n
        i += 1
    else:
        for j in range(len(pairs)):
            id2 = order[j]
            if pairs[id2][1] * pairs[id][1] < k:
                k -= pairs[id2][1] * pairs[id][1]
            else:
                print(pairs[id][0], pairs[id2][0])
                break
        break
