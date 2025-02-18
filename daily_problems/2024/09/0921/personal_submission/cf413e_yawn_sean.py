# Submission link: https://codeforces.com/contest/413/submission/282146836
inf = 10 ** 6
class SegTree:
    def __init__(self, grid) -> None:
        self._n = len(grid[0])
        self._log = (self._n - 1).bit_length()
        self._size = 1 << self._log
        
        self._d00 = [inf] * (2 * self._size)
        self._d01 = [inf] * (2 * self._size)
        self._d10 = [inf] * (2 * self._size)
        self._d11 = [inf] * (2 * self._size)

        for i in range(self._n):
            if grid[0][i] == '.':
                self._d00[self._size + i] = 0
            if grid[1][i] == '.':
                self._d11[self._size + i] = 0
            if grid[0][i] == '.' and grid[1][i] == '.':
                self._d01[self._size + i] = 1
                self._d10[self._size + i] = 1
        
        for i in range(self._size - 1, 0, -1):
            self._d00[i] = fmin(self._d00[2 * i] + self._d00[2 * i + 1], self._d01[2 * i] + self._d10[2 * i + 1])
            self._d01[i] = fmin(self._d00[2 * i] + self._d01[2 * i + 1], self._d01[2 * i] + self._d11[2 * i + 1])
            self._d10[i] = fmin(self._d10[2 * i] + self._d00[2 * i + 1], self._d11[2 * i] + self._d10[2 * i + 1])
            self._d11[i] = fmin(self._d10[2 * i] + self._d01[2 * i + 1], self._d11[2 * i] + self._d11[2 * i + 1])

    def prod(self, left: int, right: int) -> typing.Any:
        left += self._size
        right += self._size
        
        ld00, ld01, ld10, ld11 = 0, inf, inf, 0
        rd00, rd01, rd10, rd11 = 0, inf, inf, 0

        while left < right:
            if left & 1:
                ld00, ld01, ld10, ld11 = fmin(ld00 + self._d00[left], ld01 + self._d10[left]),\
                            fmin(ld00 + self._d01[left], ld01 + self._d11[left]),\
                            fmin(ld10 + self._d00[left], ld11 + self._d10[left]),\
                            fmin(ld10 + self._d01[left], ld11 + self._d11[left])
                left += 1
            if right & 1:
                right -= 1
                rd00, rd01, rd10, rd11 = fmin(self._d00[right] + rd00, self._d01[right] + rd10),\
                            fmin(self._d00[right] + rd01, self._d01[right] + rd11),\
                            fmin(self._d10[right] + rd00, self._d11[right] + rd10),\
                            fmin(self._d10[right] + rd01, self._d11[right] + rd11)

            left >>= 1
            right >>= 1

        return fmin(ld00 + rd00, ld01 + rd10),\
            fmin(ld00 + rd01, ld01 + rd11),\
            fmin(ld10 + rd00, ld11 + rd10),\
            fmin(ld10 + rd01, ld11 + rd11)

def main():
    n, q = MII()
    grid = [I() for _ in range(2)]

    seg = SegTree(grid)
    outs = []

    for _ in range(q):
        u, v = GMI()
        
        sl, l = divmod(u, n)
        sr, r = divmod(v, n)
        
        if l > r:
            l, r = r, l
            sl, sr = sr, sl

        ans = seg.prod(l, r + 1)[sl * 2 + sr] + r - l
        outs.append(ans if ans < inf else -1)

    print('\n'.join(map(str, outs)))