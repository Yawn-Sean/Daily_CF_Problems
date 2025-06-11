import sys
input = lambda: sys.stdin.readline().strip()
from queue import PriorityQueue

n = int(input())
t, w = [], []
for _ in range(n):
    tt, ww = map(int, input().split())
    t.append(tt)
    w.append(ww)
idx = sorted(range(1, n), key = lambda x: t[x], reverse = True)
ans, j = n, 0
q = PriorityQueue()
for i in range(n):
    while j < n - 1 and t[idx[j]] > t[0]:
        q.put(w[idx[j]] - t[idx[j]] + 1)
        j += 1
    ans = min(ans, j - i + 1)
    tp = 10 ** 18 + 1
    if q.qsize():
        tp = q.get()
    if tp > t[0]:
        break
    t[0] -= tp
print(ans)

