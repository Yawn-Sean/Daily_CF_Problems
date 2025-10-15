"""
速度分解，每个方向的速度分别考虑
通过 y 方向的速度以及坐标，可以算出时间
对于 x 方向，根据这个时间可以算出 x 方向的移动距离，通过调整可以实现反射
z 方向也是类似的
"""

a, b, m = map(int, input().split())
vx, vy, vz = map(int, input().split())

vy *= -1
t = m / vy
dx = t * vx
if dx > 0:
    if dx <= a / 2:
        x0 = a / 2 + dx
    else:
        dx -= a / 2
        direction = -1
        while dx > a:
            dx -= a
            direction *= -1
        if direction == -1:
            x0 = a - dx
        else:
            x0 = dx
else:
    dx *= -1
    if dx <= a / 2:
        x0 = a / 2 - dx
    else:
        dx -= a / 2
        direction = 1
        while dx > a:
            dx -= a
            direction *= -1
        if direction == -1:
            x0 = a - dx
        else:
            x0 = dx

dz = t * vz
direction = 1
while dz > b:
    dz -= b
    direction *= -1
if direction == -1:
    z0 = b - dz
else:
    z0 = dz

print(x0, z0)
