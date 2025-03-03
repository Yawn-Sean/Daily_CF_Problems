import sys
from math import gcd, lcm

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/592/C

w和b比赛，w一步只能走w米， b一步只能走b米，在赛道的终点是一个深渊（abyss），超过终点的距离会掉下去。
现在输入一个数t，比赛赛道长度在1~t之间，问w和b打平的概率（注意a和b走的不能超过终点）

输入
输入三个数，赛道最长长度t，w一步的距离，b一步的距离

输出
a和b打平的概率


如果w = b，那么概率为1/1
除以lcm(w, b)余数相同的L就是能打平的长度
'''
t, w, b = RII()
if w > b:
    w, b = b, w
if w == b:
    print('1/1')
else:
    x = lcm(w, b)
    ans = w - 1
    cnt = t // x
    ans += cnt + (w - 1) * (cnt - 1) + mn(t % x, w - 1) # %x = 0的t有cnt个，%x = [1, w - 1]的有cnt - 1个，加上最后一个周期里符合要求的数
    g = gcd(ans, t)
    print(str(ans // g) + '/' + str(t // g))