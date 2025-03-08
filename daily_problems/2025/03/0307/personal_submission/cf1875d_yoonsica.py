import sys
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
给出一个长度为 n 的序列 a，每次从中删除一个数直到删完，求每次删数之后的序列的 mex 的和的最小值
'''
for _ in range(RI()):
    n = RI()
    cnt = [0] * (n + 1)
    for x in RILIST():
        if x < n:
            cnt[x] += 1
    mex = 0
    while mex < n and cnt[mex]:
        mex += 1
    if mex == 0:
        print(0)
    else:
        # @lru_cache(None)
        # def dfs(i): # 让mex变成i的最小代价
        #     if i == mex:
        #         return 0
        #     ans = inf
        #     for j in range(i + 1, mex + 1):
        #         ans = mn(ans, (cnt[i] - 1) * j + dfs(j) + i)
        #     return ans
        # print(dfs(0))
        
        f = [inf] * (mex + 1) # 让mex变成i的最小代价
        f[mex] = 0
        for i in range(mex, -1, -1):
            for j in range(i + 1, mex + 1):
                f[i] = mn(f[i], (cnt[i] - 1) * j + f[j] + i) # 变成i之后那次的mex是i
        print(f[0])