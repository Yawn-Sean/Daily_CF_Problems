import sys
from math import comb

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/1599/C
你和你的对手一起玩一个游戏，该游戏共有 n 张地图，系统会先从中随机选择 3 张，你和你的对手需要各自从中选择一张删去（可以相同），
系统会在剩下的若干张中随机选一张作为本次游戏的地图
为了赢得更多的胜利，你想预先学习一些地图。但是由于时间有限，你希望学习尽量少的地图，并且满足每次玩到自己学习过的地图的概率至少为 p。
请问满足条件最少需要学习的地图数是多少。对手不知道你预习了哪些地图。
'''

'''
二分
'''

s = RS().split()
n = int(s[0])
p = float(s[1])
l, r = -1, n + 1

'''
检查学习mid张图，能否满足最后选到学过图的概率至少为p
'''
def check(mid):
    # 先计算3张里选1张的概率
    p1 = mid * comb(n - mid, 2) / comb(n, 3)
    # 这一张没被删除，另外两张删除1张 ，1个三选1,1个二选1 然后*2，然后系统2选1
    # 另外两张删除2，1个三选1，1个二选1，然后*2，然后1选1
    p3 = p1 / 6 + p1 / 3
    if p3 >= p:
        return True
    # 3选2,3
    p3 += comb(mid, 2)*comb(n - mid, 1) / comb(n, 3) + comb(mid, 3) / comb(n, 3)
    return p3 >= p

while l + 1 < r:
    mid = l + r >> 1
    if check(mid):
        r = mid
    else:
        l = mid
print(r)