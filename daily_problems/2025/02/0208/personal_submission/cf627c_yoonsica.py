import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/627/C

**问题描述**
Johnny 驾驶卡车从家乡前往城区中心运送货物。已知：
- 家乡位于数轴原点 $O$，城区中心位于点 $D$（$D > 0$）。
- 卡车油箱最大容量为 $N$ 升，出发时油箱已加满。
- 每行驶 1 单位距离消耗 1 升汽油。
- 途中有 $M$ 个加油站，第 $i$ 个加油站位置为 $x_i$（$0 < x_i < D$），每升汽油价格为 $p_i$ 美元。

**任务**
求 Johnny 完成运送任务所需的最小费用（单位：美元）。
10 4 4
3 5
5 8
6 3
8 4

思路：
参考别人思路：
加油站按距离排序
单调栈预处理每个加油站后面比自己便宜的最近加油站
贪心
如果能走到目标，则加油恰好走到目标去加更便宜的油
否则，中间的加油站都更贵，直接加满最优，走到下一个加油站，再次判断否走到更便宜的加油站
'''
d, n, m = RII()
p = [[0,  10**6 + 1]]
for _ in range(m):
    p.append(RILIST())
p.append([d, 0])
p.sort()
right = [m + 1] * (m + 2)
st = []
for i, (x, cost) in enumerate(p):
    while st and p[st[-1]][1] > cost:
        right[st.pop()] = i
    st.append(i)

ans, cur = 0, n
i = 0
while i < m + 1:
    x, cost = p[i]
    if p[right[i]][0] - x <= n: # 加满能走到
        ans += mx(0, p[right[i]][0] - x - cur) * cost
        cur = mx(0, cur - p[right[i]][0] + x)
        i = right[i]
    else:
        ans += cost * (n - cur)
        cur = n - (p[i + 1][0] - x)
        if cur < 0:
            print(-1)
            exit()
        i += 1
print(ans)
