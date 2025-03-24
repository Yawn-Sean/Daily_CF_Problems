def main():
    n, x1, y1, x2, y2 = MII()
    pos = []
    dist1, dist2 = [], []
    for _ in range(n):
        xi, yi = MII()
        pos.append([xi, yi])
        dist1.append((x1 - xi) ** 2 + (y1 - yi) ** 2)
        dist2.append((x2 - xi) ** 2 + (y2 - yi) ** 2)
    sortedIdx = sorted(range(n), key=lambda p: dist1[p])
    cnt = Counter(dist2)
    h = [-d for d in dist2]
    heapify(h)
    ans = -h[0]
    for i in sortedIdx:
        cnt[dist2[i]] -= 1
        while h and cnt[-h[0]] == 0:
            heappop(h)
        ans = fmin(ans, (-h[0] if h else 0) + dist1[i])
    return ans


T = 1
for ii in range(T):
    print(main())
