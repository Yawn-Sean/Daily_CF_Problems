import sys
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x


'''
https://codeforces.com/problemset/problem/1028/D
给定两个集合A,B，要求A中所有元素小于B中的元素
给定n个操作：
ADD x：x加入任意集合
Accept x：删除x，要求此时x必须是集合A中的最大，或者B中最小元素
求add的合法方案
'''

'''
思路：
本题参考别人的题解，自己没思路。
考虑ADD 1 5 3，没有ACCEPT的情况下，有？种可能，要求A（买入报价）元素小于B（卖出报价）
A: 1 3  B:5
A: 1    B:5 3
A: 1 5  B:3 这种不合理，3<5,
A: 1 5 3
B: 1 5 3
所以相当于把1 5 3排序，然后加挡板划分两个集合，x个数有x + 1个方案
维护left和right，代表目前A的最大值的最小值，B中的最小值的最大值，那么left <= x <= right的元素有两种选择，放哪里都行，用一个有序集合维护这些数
当Accept这中间的数时，相当于把集合划分成两部分，x的左边A，右边B，新的left和right就是x左右两个元素.
最后在left right间未accept的数有cnt + 1种放法
'''
mod = 10**9 + 7
ans = 1
sl = SortedList()
sl.add(-inf)
sl.add(inf)
left, right = -inf, inf
cnt = 1
for _ in range(RI()):
    op, x = RS().split()
    x = int(x)
    if op == 'ADD':
        sl.add(x)
        if left < x < right:
            cnt += 1
    else:
        cnt = 1
        if x < left or x > right:
            print(0)
            exit(0)
        if left < x < right:
            ans *= 2
            ans %= mod
        idx = sl.bisect_left(x)
        left, right = sl[idx - 1], sl[idx + 1]
        sl.remove(x)
ans = (ans * cnt) % mod
print(ans)
        