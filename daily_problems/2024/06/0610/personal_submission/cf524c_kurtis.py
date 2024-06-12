import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 就是两数之和问题
n, k = MII()
a = LMII()
cnt = Counter()

for x in a:
    for i in range(1, k + 1):
        cnt[x * i] = i
        
cnt[0] = 0
q = II()
ans = []
for _ in range(q):
    t = II()
    res = k + 1
    for x in cnt:
        if t - x in cnt:
            res = min(res, cnt[x] + cnt[t - x])
    ans.append(-1 if res > k else res)
print(*ans, sep='\n')