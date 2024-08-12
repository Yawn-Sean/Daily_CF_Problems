import random
import sys
import typing

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

class SegTree:
    def __init__(self,
                 op: typing.Callable[[typing.Any, typing.Any], typing.Any],
                 e: typing.Any,
                 v: typing.Union[int, typing.List[typing.Any]]) -> None:
        self._op = op
        self._e = e
 
        if isinstance(v, int):
            v = [e] * v
 
        self._n = len(v)
        self._log = (self._n - 1).bit_length()
        self._size = 1 << self._log
        self._d = [e] * (2 * self._size)
 
        for i in range(self._n):
            self._d[self._size + i] = v[i]
        for i in range(self._size - 1, 0, -1):
            self._update(i)
 
    def set(self, p: int, x: typing.Any) -> None:
        assert 0 <= p < self._n
 
        p += self._size
        self._d[p] = x
        for i in range(1, self._log + 1):
            self._update(p >> i)
 
    def get(self, p: int) -> typing.Any:
        assert 0 <= p < self._n
 
        return self._d[p + self._size]
 
    def prod(self, left: int, right: int) -> typing.Any:
        assert 0 <= left <= right <= self._n
        sml = self._e
        smr = self._e
        left += self._size
        right += self._size
 
        while left < right:
            if left & 1:
                sml = self._op(sml, self._d[left])
                left += 1
            if right & 1:
                right -= 1
                smr = self._op(self._d[right], smr)
            left >>= 1
            right >>= 1
 
        return self._op(sml, smr)
 
    def all_prod(self) -> typing.Any:
        return self._d[1]
 
    def max_right(self, left: int,
                  f: typing.Callable[[typing.Any], bool]) -> int:
        assert 0 <= left <= self._n
        assert f(self._e)
 
        if left == self._n:
            return self._n
 
        left += self._size
        sm = self._e
 
        first = True
        while first or (left & -left) != left:
            first = False
            while left % 2 == 0:
                left >>= 1
            if not f(self._op(sm, self._d[left])):
                while left < self._size:
                    left *= 2
                    if f(self._op(sm, self._d[left])):
                        sm = self._op(sm, self._d[left])
                        left += 1
                return left - self._size
            sm = self._op(sm, self._d[left])
            left += 1
 
        return self._n
 
    def min_left(self, right: int,
                 f: typing.Callable[[typing.Any], bool]) -> int:
        assert 0 <= right <= self._n
        assert f(self._e)
 
        if right == 0:
            return 0
 
        right += self._size
        sm = self._e
 
        first = True
        while first or (right & -right) != right:
            first = False
            right -= 1
            while right > 1 and right % 2:
                right >>= 1
            if not f(self._op(self._d[right], sm)):
                while right < self._size:
                    right = 2 * right + 1
                    if f(self._op(self._d[right], sm)):
                        sm = self._op(self._d[right], sm)
                        right -= 1
                return right + 1 - self._size
            sm = self._op(self._d[right], sm)
 
        return 0
 
    def _update(self, k: int) -> None:
        self._d[k] = self._op(self._d[2 * k], self._d[2 * k + 1])

# hint：You can process the queries offline. If the left bound is fixed, how can you solve it?
# 固定左端点，只需枚举这个区间中的最小值，可以用线段树
# 变化左端点，则只需要改变ne[l]的值
# 所以做法就是按照左端点排序

n, q = MII()
a = LMII()

ne, pre = [n] * n, [-1] * n

pos = {} # 用字典来离散化
for i in range(n):
    if a[i] in pos:
        pre[i] = pos[a[i]] # 记录前一个位置
    pos[a[i]] = i
pos = {} 
for i in range(n - 1, -1, -1):
    if a[i] in pos:
        ne[i] = pos[a[i]] # 记录下一个位置
    pos[a[i]] = i

ls, rs = [], []
for _ in range(q):
    l, r = GMI()
    ls.append(l)
    rs.append(r)

qry = sorted(range(q), key=lambda i: ls[i]) # 按照左端点排序
ans = [-1] * q

seg = SegTree(min, n, [i - pre[i] if pre[i] >= 0 else n for i in range(n)]) 

pt = 0 # 当前的左端点
for i in qry:
    while pt < ls[i]:
        if ne[pt] < n: # 把下一个点更新
            seg.set(ne[pt], n)
        pt += 1
    ans[i] = seg.prod(ls[i], rs[i] + 1) # 左开右闭

print(*[x if x < n else -1 for x in ans], sep='\n')