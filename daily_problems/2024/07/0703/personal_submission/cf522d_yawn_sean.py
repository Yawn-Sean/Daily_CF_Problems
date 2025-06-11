# Submission Link: https://codeforces.com/contest/522/submission/268539267
def main():
    rnd = random.getrandbits(20)

    n, q = MII()
    nums = [x ^ rnd for x in MII()]

    next_pos = [n] * n
    last_pos = [-1] * n

    pos = {}
    for i in range(n):
        if nums[i] in pos:
            last_pos[i] = pos[nums[i]]
        pos[nums[i]] = i

    pos = {}
    for i in range(n - 1, -1, -1):
        if nums[i] in pos:
            next_pos[i] = pos[nums[i]]
        pos[nums[i]] = i

    ls = []
    rs = []

    for _ in range(q):
        l, r = GMI()
        ls.append(l)
        rs.append(r)

    st_range = sorted(range(q), key=lambda x: ls[x])
    ans = [-1] * q

    fmin = lambda x, y: x if x < y else y
    seg = SegTree(fmin, n, [i - last_pos[i] if last_pos[i] >= 0 else n for i in range(n)])

    pt = 0
    for i in st_range:
        while pt < ls[i]:
            if next_pos[pt] < n:
                seg.set(next_pos[pt], n)
            pt += 1
        ans[i] = seg.prod(ls[i], rs[i] + 1)

    print('\n'.join(str(x) if x < n else '-1' for x in ans))