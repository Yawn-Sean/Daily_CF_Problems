def solve():
    import sys

    input = sys.stdin.readline

    n, m = map(int, input().split())
    arr = [tuple(map(int, input().split())) + (i,) for i in range(m)]
    num = [0] * m

    from collections import defaultdict

    buckets = defaultdict(list)
    for x, y, idx in arr:
        buckets[x].append((y, idx))
    for x_key in buckets:
        buckets[x_key].sort(key=lambda p: p[0])
        group = buckets[x_key]
        for i in range(len(group)):
            if i > 0:
                num[group[i][1]] += 1
                num[group[i - 1][1]] += 1

    buckets.clear()
    for x, y, idx in arr:
        buckets[y].append((x, idx))
    for y_key in buckets:
        buckets[y_key].sort(key=lambda p: p[0])
        group = buckets[y_key]
        for i in range(len(group)):
            if i > 0:
                num[group[i][1]] += 1
                num[group[i - 1][1]] += 1

    buckets.clear()
    for x, y, idx in arr:
        buckets[x + y].append((x, idx))
    for s_key in buckets:
        buckets[s_key].sort(key=lambda p: p[0])
        group = buckets[s_key]
        for i in range(len(group)):
            if i > 0:
                num[group[i][1]] += 1
                num[group[i - 1][1]] += 1

    buckets.clear()
    for x, y, idx in arr:
        buckets[x - y].append((y, idx))
    for d_key in buckets:
        buckets[d_key].sort(key=lambda p: p[0])
        group = buckets[d_key]
        for i in range(len(group)):
            if i > 0:
                num[group[i][1]] += 1
                num[group[i - 1][1]] += 1

    ans = [0] * 9
    for c in num:
        ans[c] += 1
    print(*ans)


if __name__ == "__main__":
    solve()
