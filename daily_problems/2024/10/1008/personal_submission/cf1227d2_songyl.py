import collections
from bisect import bisect_left as lower_bound
from bisect import bisect_right as upper_bound

# class FenwickTree:
    # 数据结构省略

# class SortedList:
    # 数据结构省略


slist = SortedList()

n = int(input())
a = [int(i) for i in input().split(" ")]
aa = [[x, i] for i, x in enumerate(a)]
aa.sort(key=lambda x: (-x[0], x[1]))
aa = collections.deque(aa)

m = int(input())
queries = []
for i in range(m):
    oq = [int(i) for i in input().split(" ")]
    oq.append(i)
    queries.append(oq)

queries.sort(key=lambda x: x[0])
ans = [0] * len(queries)
pre_k = 0

for k, j, ind in queries:
    if pre_k != k:
        for i in range(k-pre_k):
            slist.insert(aa.popleft()[1])
    ans[ind] = a[slist[j - 1]]
    pre_k = k

for r in ans:
    print(r)


