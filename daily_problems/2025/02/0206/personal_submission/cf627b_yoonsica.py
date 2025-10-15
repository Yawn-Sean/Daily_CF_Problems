import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/627/B

长度位n的数组t, 三个数a, b, k,初始a[i] = 0
两种操作：
第一种: 1 x y 将t[x]改成y
第二种：2 x 计算 sum(min(t[x], b) for x in range(1, x)) + sum(min(t[x], a) for x in range(x + k, n + 1))
输出第二种操作后的结果

思路：
区间修改+区间查询，用线段树
'''


class Node:
    def __init__(self, a=0, b=0):
        self.a = a
        self.b = b

class SegmentTree:
    def __init__(self, n):
        self.n = n
        self.vals = [0] * (n + 1)
        self.trees = [Node(0, 0) for _ in range(4 * n)]
    
    def push_up(self, x, y):
        return Node(x.a + y.a, x.b + y.b)
    
    def update(self, o, s, e, i, v):
        if s == e:
            self.vals[i] += v
            self.trees[o].b = mn(b, self.vals[i])
            self.trees[o].a = mn(a, self.vals[i])
            return
        mid = s + e >> 1
        if mid >= i:
            self.update(o * 2, s, mid, i, v)
        else:
            self.update(o * 2 + 1, mid + 1, e, i, v)
        self.trees[o] = self.push_up(self.trees[o * 2], self.trees[o * 2 + 1])
    
    def query(self, o, s, e, l, r):
        if l <= s <= e <= r:
            return self.trees[o]
        mid = s + e >> 1
        if mid >= r:
            return self.query(o * 2, s, mid, l, r)
        if l >= mid + 1:
            return self.query(o * 2 + 1, mid + 1, e, l, r)
        return self.push_up(self.query(o * 2, s, mid, l, r), self.query(o * 2 + 1, mid + 1, e, l, r))


n, k, a, b, q = RII()
st = SegmentTree(n)
for _ in range(q):
    t = RILIST()
    if t[0] == 1:
        st.update(1, 1, n, t[1], t[2])
    else:
        ans = 0
        if t[1] > 1:
            ans += st.query(1, 1, n, 1, t[1] - 1).b
        if t[1] + k <= n:
            ans += st.query(1, 1, n, t[1] + k, n).a
        print(ans)