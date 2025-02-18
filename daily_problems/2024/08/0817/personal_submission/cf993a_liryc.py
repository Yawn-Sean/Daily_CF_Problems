'''
https://codeforces.com/contest/993/submission/276868254
993A
2024/8/17 Y1
1600
计算几何
'''

# s: 正方形 
# 判断(x, y)是否在s内部
def checkOne(s, x, y):
    xa, ya = [s[i] for i in range(0, 8, 2)], [s[i] for i in range(1, 8, 2)]
    return min(xa) <= x <= max(xa) and min(ya) <= y <= max(ya)

# s: 正方形 d: 菱形
# 判断菱形四个端点及中心点是否在正方形内部
def check(s, d):
    checkResult = any(checkOne(s, d[i], d[i + 1]) for i in range(0, 8, 2))
    if not checkResult:
        xa, ya = [d[i] for i in range(0, 8, 2)], [d[i] for i in range(1, 8, 2)]
        x, y = min(xa) + max(xa) >> 1, min(ya) + max(ya) >> 1
        checkResult = checkOne(s, x, y)
    return checkResult

a = list(map(lambda t: int(t) + 100 << 1, input().split()))
b = list(map(lambda t: int(t) + 100 << 1, input().split()))
ans = check(a, b)
if not ans:
    ac, bc = [0] * 8, [0] * 8
    for i in range(0, 8, 2):
        x, y = a[i:i + 2]
        ac[i:i + 2] = x + y, x - y
        x, y = b[i:i + 2]
        bc[i:i + 2] = x + y, x - y
    ans = check(bc, ac)
if ans:
    print("YES")
else:
    print("NO")