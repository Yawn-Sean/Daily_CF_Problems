# Submission link: https://codeforces.com/contest/431/submission/277851028
def main():
    n, q = MII()
    nums = LII()

    volumes = nums[:]

    xs = []
    ys = []

    for _ in range(q):
        query = LII()
        if query[0] == 1:
            xs.append(query[1] - 1)
            ys.append(query[2])
            volumes.append(query[2])
        else:
            xs.append(-1)
            ys.append(query[1])

    volumes = sorted(set(sorted(volumes)))
    d = {v: i for i, v in enumerate(volumes)}
    k = len(d)

    def f(total_volume, volume, size):
        return (total_volume * (10 ** 9 + 1) + volume) * (n + 1) + size

    def revf(msk):
        msk, size = divmod(msk, n + 1)
        total_volume, volume = divmod(msk, 10 ** 9 + 1)
        return total_volume, volume, size

    def op(msk1, msk2):
        if msk2 == 0: return msk1
        if msk1 == 0: return msk2
        total_volume1, volume1, size1 = revf(msk1)
        total_volume2, volume2, size2 = revf(msk2)
        return f(total_volume1 + total_volume2 + (volume2 - volume1) * size1, volume2, size1 + size2)

    ar = [f(0, x, 0) for x in volumes]
    for num in nums:
        ar[d[num]] += 1

    seg = SegTree(op, 0, ar)
    total_msk = (10 ** 9 + 1) * (n + 1)

    outs = []
    for i in range(q):
        if ~xs[i]:
            v = d[nums[xs[i]]]
            ar[v] -= 1
            seg.set(v, ar[v])
            
            nums[xs[i]] = ys[i]
            
            v = d[nums[xs[i]]]
            ar[v] += 1
            seg.set(v, ar[v])
        else:
            idx = seg.max_right(0, lambda x: x // total_msk <= ys[i])
            total_volume, volume, size = revf(seg.prod(0, idx))
            outs.append(volume + (ys[i] - total_volume) / size)

    print('\n'.join(map(str, outs)))