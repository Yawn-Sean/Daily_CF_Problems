from collections import *
from math import *
del pow
find = defaultdict(list)
f = defaultdict(list)
n, k = map(int, input().split())
arr = []
for _ in range(n):
    a, b, c = map(int, input().split())
    find[b - a + 1].append((a, b, c))
    arr.append((a, b, c))
for key in find.keys():
    find[key].sort(key=lambda x: (x[1], -x[2]))
    f[key] = []
    num = inf
    for i, (a, b, c) in enumerate(find[key]):
        num = min(num, c)
        f[key].append(num)
arr.sort(key=lambda x: x[0])
res = inf
for _ in range(n):
    a1, b1, c1 = arr.pop()
    p = b1 - a1 + 1
    tar = k - p
    if tar <= 0:
        continue
    else:
        while find[tar]:
            a2, b2, c2 = find[tar].pop()
            ans = f[tar].pop()
            if b2 < a1:
                res = min(res, c1 + ans)
                find[tar].append((a2, b2, c2))
                f[tar].append(ans)
                break
print(res) if res != inf else print(-1)
