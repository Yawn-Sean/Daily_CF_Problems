import sys
from heapq import heappush, heappop

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 参考村长在堆中同时维护权值和下标的写法
n, k = MII()
a = LGMI() # 可以少开一个空间

pos = [n] * n
nxt = [n] * n

for i in range(n - 1, -1, -1):
    nxt[i] = pos[a[i]] # 上一次a[i]出现的位置
    pos[a[i]] = i
    
h = []
st = [False] * n
cnt = 0 # 书的数量
ans = 0

for i in range(n):
    if not st[a[i]]:
        if cnt == k: # 要换书
            st[heappop(h) % n] = False
            cnt -= 1
        st[a[i]] = True

        cnt += 1
        ans += 1
    heappush(h, -nxt[i] * n + a[i]) # 加入新的记录，原来的记录一定不会被选到
print(ans)