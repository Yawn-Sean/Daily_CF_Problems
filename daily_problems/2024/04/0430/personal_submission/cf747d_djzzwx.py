def solve() -> None:
    n, k = map(int, input().split())
    a = ints()
    cnt = p = tot = 0
    pi = -1
    gap = []
    for i, v in enumerate(a):
        tot += v < 0
        if v < 0:
            cnt += p >= 0
            if pi >= 0 and i - pi > 1:
                heappush(gap, i - pi - 1)
            pi = i
        elif v >= 0:
            cnt += p < 0
        p = v
    if tot > k:
        print(-1)
        return
    k -= tot
    while k > 0 and gap and gap[0] <= k:
        k -= heappop(gap)
        cnt -= 2
    if pi >= 0 and n - pi > 1 and n - pi - 1 <= k:
        cnt -= 1
    print(cnt)


for _ in range(1):
    solve()