import heapq

outs = []
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = []
    for i in range(n):
        x, y = map(int, input().split())
        a.append((x, y))

    a.sort(key = lambda x: x[1])

    pq = []
    ans = -10 ** 18
    now = 0
    for i in range(n):
        now += a[i][0]
        heapq.heappush(pq, a[i][0])
        if len(pq) == k:
            ans = max(ans, now - a[i][1])
            now -= heapq.heappop(pq)

    outs.append(ans)

print('\n'.join(map(str, outs)))
