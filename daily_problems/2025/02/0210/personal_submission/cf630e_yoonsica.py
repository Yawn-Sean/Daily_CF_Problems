import sys

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/630/E

思路：
给定坐标范围，然后数这个范围内有多少个中心点
初始放（y2 - y1 + 2)//2个，然后-1 +1交替
'''
x1, y1, x2, y2 = RII()
ans = 0
cnt = (y2 - y1 + 2) // 2 # 上下都可以出去一半
ans += cnt * (x2 - x1 + 1) - (x2 - x1 + 1) // 2
print(ans)
