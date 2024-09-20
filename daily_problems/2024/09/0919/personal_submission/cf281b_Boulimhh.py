"""
思路: 通分, 通过交叉相乘判断当前的分数 𝑎/𝑏 是否比之前的分数更接近目标 𝑥/𝑦
"""
#python代码:
x, y, n = map(int, input().split())
tx, ty = 1, 0
dx, dy = x, y

for b in range(1, n + 1):
    v = b * x // y
    for a in range(v, v + 2):
        ndx, ndy = abs(x * b - y * a), b * y
        if ndx * dy < dx * ndy:
            tx, ty = b, a
            dx, dy = ndx, ndy
print(f'{ty}/{tx}')
