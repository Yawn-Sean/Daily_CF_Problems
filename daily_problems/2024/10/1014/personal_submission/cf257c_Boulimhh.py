"""
思路：学到的一集，可以用最大间隔来代表最小角度的对立面。

"""
#python代码：
n = int(input())
ang = []
for _ in range(n):
    x, y = map(int, input().split())
    ang.append(atan2(y, x))
ang.sort()
ans = 0
for i in range(n - 1):
    ans = max(ans, ang[i + 1] - ang[i])
print(min(2 * pi - ans, ang[-1] - ang[0]) / pi * 180)
