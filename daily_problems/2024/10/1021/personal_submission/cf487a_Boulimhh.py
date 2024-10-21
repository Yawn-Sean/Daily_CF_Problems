"""
直接上代码，无需多言
"""
#python代码：
x1, gj1, fy1 = map(int, input().split())
x2, gj2, fy2 = map(int, input().split())
x, gj, fy = map(int, input().split())
# 保证能打掉monster血条, 加gj
cost = 0
v = fmax(0, fy2 + 1 - gj1)
gj1 += v
cost += v * gj
# Master 被打掉几滴血
bd = fmax(0, gj2 - fy1)
dd = gj1 - fy2
# Master 能打掉几滴血
costs = bd * fy # 都买fy，不掉血
for f_y in range(bd): # 看买多少防御合适
    for g_j in range(101): # 防御不行，买攻击
        h1 = bd - f_y # 加防御
        h2 = dd + g_j # 加攻击
        time = (x2 + h2 - 1) // h2 
        hl = fmax(time * h1 + 1 - x1, 0)
        costs = fmin(costs, f_y * fy + g_j * gj + hl * x) # 买点药也行
print(cost + costs)
