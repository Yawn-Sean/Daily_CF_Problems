import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
n, x = MII()
events = []
for _ in range(n):
    ll, rr, ccost = MII()
    length = rr - ll + 1
    if length <= x:
        events.append((ll, 0, length, ccost))
        events.append((rr, 1, length, ccost))
events.sort()
inf = 10**18
best_len = [inf] * (x + 1)
ans = inf

for pos, typ, length, cost in events:
    if typ == 0:
        need = x - length
        if 0 < need <= x and best_len[need] != inf:
            ans = min(ans, best_len[need] + cost)
    else:
        if cost < best_len[length]:
            best_len[length] = cost

print(-1 if ans == inf else ans)
