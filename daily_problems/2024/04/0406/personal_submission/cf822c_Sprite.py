from math import inf
from bisect import bisect_left
n, x = map(int, input().split())
trip = []
for _ in range(n):
    trip.append(list(map(int, input().split())))
trip.sort()

lst = [[[] for _ in range(2)] for _ in range(x)]
ans = inf

for l, r, c in trip:
    dur = r - l + 1
    if dur < x:
        k = bisect_left(lst[x - dur][0], l)
        if k:
            ans = min(ans, c + lst[x - dur][1][k-1])
    if dur < x:
        if lst[dur][0] and c >= lst[dur][1][-1]:
            continue
        lst[dur][0].append(r)
        lst[dur][1].append(c)
print(ans if ans != inf else -1)
