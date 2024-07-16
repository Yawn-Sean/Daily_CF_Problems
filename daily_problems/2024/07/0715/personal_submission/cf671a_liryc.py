'''
CF671A 2024/7/15 Y1
1800
first and second best answer
'''
from math import inf

ax, ay, bx, by, tx, ty = map(int, input().split())
n = int(input())

def f1(x, y):
    return ((x - ax) * (x - ax) + (y - ay) * (y - ay)) ** 0.5

def f2(x, y):
    return ((x - bx) * (x - bx) + (y - by) * (y - by)) ** 0.5

def f(x, y):
    return ((x - tx) * (x - tx) + (y - ty) * (y - ty)) ** 0.5

tot = 0
dp1 = dp2 = dp3 = -4e9

for _ in range(n):
    x, y = map(int, input().split())
    tot += 2 * f(x, y)
    dp1, dp2, dp3 = max(dp1, f(x, y) - f1(x, y)), max(dp2, f(x, y) - f2(x, y)),\
                    max(dp3, dp1 + f(x, y) - f2(x, y), dp2 + f(x, y) - f1(x, y))

print(tot - max(dp1, dp2, dp3))

'''没想明白为什么自己的方法不行,感觉跟题解的思路基本一样
a1i, a1d, a2i, a2d, b1i, b1d, b2i, b2d = -1, -inf, -1, -inf, -1, -inf, -1, -inf
sumd = 0.0
pa = []
for i in range(n):
    x, y = map(int, input().split())
    pa.append((x, y))
    d = ((tx - x) ** 2 + (ty - y) ** 2) ** 0.5
    sumd += d * 2
    da = d - ((ax - x) ** 2 + (ay - y) ** 2) ** 0.5
    db = d - ((bx - x) ** 2 + (by - y) ** 2) ** 0.5
    if da > a1d: 
        a1d, a1i, a2d, a2i = da, i, a1d, a1i
    elif da > a2d:
        a2d, a2i = da, i
    if db > b1d:
        b1d, b1i, b2d, b2i = db, i, b1d, b1i
    elif db > b2d:
        b2d, b2i = db, i
ans = 0.0
ai, bi = -1, -1
if a1i != b1i:
    ai, bi = a1i, b1i
elif a1d + b2d > a2d + b1d:
    ai, bi = a1i, b2i
else:
    ai, bi = a2i, b1i
sumd = 0.0
for i, (x, y) in enumerate(pa):
    d = ((tx - x) ** 2 + (ty - y) ** 2) ** 0.5
    if i == ai:
        sumd = sumd + ((ax - x) ** 2 + (ay - y) ** 2) ** 0.5 + d
    elif i == bi:
        sumd = sumd + ((bx - x) ** 2 + (by - y) ** 2) ** 0.5 + d
    else:
        sumd = sumd + d + d
print(sumd)
# if a1i != b1i:
#     ans = sumd - a1d - b1d
# else:
#     ans = min(sumd - a1d - b2d, sumd - a2d - b1d)
# print(ans)

'''