import sys
from heapq import heappush, heappop

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/1183/G

n块糖果，第i块糖果种类是a[i]，f[i] = 0/1表示你是否愿意把这种糖果送人
要求送出的糖果不同种类的数量都不同，且在送出总的糖果数量最多的情况下，f[i] = 1的最多

思路：
贪心，考虑极端情况先，全选，然后处理不同种类数量相同的情况，找一种糖果，删除其中一个f[i] = 0的，
如果删除之后又和其他的种类数量相同了，就再找一个f[i] = 0的删除，谁有就删谁，优先删f[i] = 0比较多的，
如果大家都没有f[i] = 0的，那么随便删一个，因为每次要找数量最多的两种来判断是否相同，用堆模拟
'''
for _ in range(RI()):
    n = RI()
    a, b = [], []
    cnt_all = [0] * (n + 1)
    cnt_0 = [0] * (n + 1)
    for i in range(n):
        x, y = RII()
        cnt_all[x] += 1
        if y == 0:
            cnt_0[x] += 1
    
    h = []
    for i in range(1, n + 1):
        heappush(h, (cnt_all[i], cnt_0[i], i)) # 糖果数量，f[i] = 0的糖果数量，种类编号
    
    ans = ans_0 = 0
    while h:
        c1, c01, i = heappop(h)
        if not h:
            ans -= c1
            ans_0 -= c01
        else:
            c2, c02, j = h[-1]
            if c1 != c2:
                ans -= c1
                ans_0 -= c01
            else:
                if c01 <= c02 <= 0:
                    if c1 + 1 < 0:
                        heappush(h, (c1 + 1, c01 + int(c01 < 0), i))
                else:
                    if c2 + 1 < 0:
                        heappop(h)
                        heappush(h, (c2 + 1, c02 + int(c02 < 0), j))
    print(ans, ans - ans_0)
