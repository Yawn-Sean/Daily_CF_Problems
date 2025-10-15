# Submission link: https://codeforces.com/contest/2057/submission/323965004
inf = 2 * 10 ** 9

class SegTree:
    def __init__(self,
                 v: typing.Union[int, typing.List[typing.Any]]) -> None:
        self._n = len(v)
        self._log = (self._n - 1).bit_length()
        self._size = 1 << self._log
        
        self._mi1 = [inf] * (2 * self._size)
        self._ma1 = [-inf] * (2 * self._size)
        self._mi2 = [inf] * (2 * self._size)
        self._ma2 = [-inf] * (2 * self._size)
        self._ans = [0] * (2 * self._size)
        
        for i in range(self._n):
            self._mi1[self._size + i] = v[i] - i
            self._ma1[self._size + i] = v[i] - i
            self._mi2[self._size + i] = v[i] + i
            self._ma2[self._size + i] = v[i] + i
        
        for i in range(self._size - 1, 0, -1):
            self._update(i)

    def set(self, p: int, x: typing.Any) -> None:
        assert 0 <= p < self._n

        p0 = p
        p += self._size
        self._mi1[p] = x - p0
        self._ma1[p] = x - p0
        self._mi2[p] = x + p0
        self._ma2[p] = x + p0
        for i in range(1, self._log + 1):
            self._update(p >> i)

    def all_prod(self) -> typing.Any:
        return self._ans[1]

    def _update(self, k: int) -> None:
        self._mi1[k] = fmin(self._mi1[2 * k], self._mi1[2 * k + 1])
        self._ma1[k] = fmax(self._ma1[2 * k], self._ma1[2 * k + 1])
        self._mi2[k] = fmin(self._mi2[2 * k], self._mi2[2 * k + 1])
        self._ma2[k] = fmax(self._ma2[2 * k], self._ma2[2 * k + 1])
        self._ans[k] = fmax(self._ans[2 * k], self._ans[2 * k + 1])
        self._ans[k] = fmax(self._ans[k], self._ma1[2 * k + 1] - self._mi1[2 * k])
        self._ans[k] = fmax(self._ans[k], self._ma2[2 * k] - self._mi2[2 * k + 1])

def main():
    t = II()
    outs = []

    for _ in range(t):
        n, q = MII()
        nums = LII()
        
        seg = SegTree(nums)
        outs.append(seg.all_prod())
        
        for _ in range(q):
            idx, val = MII()
            idx -= 1
            
            seg.set(idx, val)
            outs.append(seg.all_prod())

    print('\n'.join(map(str, outs)))