import sys
from heapq import heapify, heappush, heappop

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 肯定是数据结构
# 双链表加堆？
# 堆中每个节点维护：长度和下标
# 每次弹出一个维护它的左右关系
# 主要是合并操作？
def delete(x):
    cnts[x] = 0
    if l[x] >= 0:
        r[l[x]] = r[x]
    if r[x] < k:
        l[r[x]] = l[x]

n = II()
a = LMII()
# 就是一段一段维护好了
vals, cnts = [], []
i = 0
while i < n:
    j = i
    while j < n and a[j] == a[i]: j += 1
    vals.append(a[i])
    cnts.append(j - i)
    i = j

k = len(vals)
l, r = list(range(-1, k - 1)), list(range(1, k + 1))
# 链表和堆中维护的都是下标
hqp = [(-cnts[i], i) for i in range(k)]
heapify(hqp)

ans = 0
while hqp:
    c, i = heappop(hqp)
    if cnts[i] != -c: continue # 说明被合并了
    ans += 1
    if l[i] >= 0 and r[i] < k and vals[l[i]] == vals[r[i]]:
        cnts[l[i]] += cnts[r[i]]
        delete(r[i]) # 直接删掉就好
        heappush(hqp, (-cnts[l[i]], l[i]))
    delete(i)
print(ans)