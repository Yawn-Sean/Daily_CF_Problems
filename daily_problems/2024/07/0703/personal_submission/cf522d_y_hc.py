def main():
    n, m = MII()
    nums = LII()
    query = [LGMI() for _ in range(m)]

    ans = [-1] * m

    d = defaultdict(list)
    for i, num in enumerate(nums):
        d[num].append(i)
    segs = []
    for key in d:
        for i in range(len(d[key]) - 1):
            segs.append((d[key][i], d[key][i + 1]))

    segs.sort(key = lambda x: x[1])
    zkw = ZKW([inf] * n, min, inf)
    ptr = 0
    for i, (l, r) in sorted(enumerate(query), key = lambda x: x[1][1]):
        while ptr < len(segs) and segs[ptr][1] <= r:
            zkw.set(segs[ptr][0], segs[ptr][1] - segs[ptr][0])
            ptr += 1

        ans[i] = zkw.query(l, r)

    for e in ans:
        if e != inf:
            print(e)
        else:
            print(-1)

T = 1
for _ in range(T):
    main()
