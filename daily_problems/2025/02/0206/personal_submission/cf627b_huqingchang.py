class SegmentTree:

    def __init__(self, arr):   # 头节点编号为1，对应数值下标区间为[0, n - 1]。入口参数直接传数组，自动生成对应的线段树
        self.n = len(arr)
        self.sums = [0] * (4 * self.n)
        self.arr = arr
        self.build(1, 0, self.n - 1)

    def build(self, idx, l, r):
        if l == r:   # 到了叶节点
            self.sums[idx] = self.arr[l]
        else:
            mid = l + r >> 1   # 经典分治
            self.build(2 * idx, l, mid)
            self.build(2 * idx + 1, mid + 1, r)
            self.sums[idx] = self.sums[2 * idx] + self.sums[2 * idx + 1]

    def update(self, idx, l, r, to_update_idx, val):
        if l == r:
            self.sums[idx] = val
        else:
            mid = l + r >> 1
            if mid >= to_update_idx:
                self.update(idx * 2, l, mid, to_update_idx, val)
            else:
                self.update(idx * 2 + 1, mid + 1, r, to_update_idx, val)
            self.sums[idx] = self.sums[idx * 2] + self.sums[idx * 2 + 1]   # 经典push_up操作，自下向上更新

    def query(self, idx, l, r, ql, qr):  # l, r 对应idx节点左右边界, ql, qr 对应查询左右边界。查询时间复杂度为o(logn)
        if ql <= l and r <= qr:
            return self.sums[idx]
        if qr < l or ql > r:
            return 0
        mid = l + r >> 1
        return self.query(idx * 2, l, mid, ql, qr) + self.query(idx * 2 + 1, mid + 1, r, ql, qr)


def main():
    n, k, a, b, q = MII()
    res = [0] * n
    sta, stb = SegmentTree(res), SegmentTree(res)
    for _ in range(q):
        order = LII()
        if order[0] == 1:
            di, ai = order[1], order[2]
            di -= 1
            res[di] += ai
            sta.update(1, 0, n - 1, di, min(a, res[di]))
            stb.update(1, 0, n - 1, di, min(b, res[di]))
        else:
            pi = order[1]
            pi -= 1
            tmp = 0
            if pi:
                tmp += stb.query(1, 0, n - 1, 0, pi - 1)
            if pi + k < n:
                tmp += sta.query(1, 0, n - 1, pi + k, n - 1)
            print(tmp)


T = 1
for ii in range(T):
    # print(main())
    main()
