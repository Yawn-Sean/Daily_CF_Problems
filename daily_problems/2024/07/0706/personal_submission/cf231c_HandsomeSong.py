def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n, k = MII()
a = LII()
a.sort()
prefix = [0] * (n + 1)
for i in range(n):
    prefix[i + 1] = prefix[i] + a[i]
max_cnt = 0
best = 0
for x in range(n):
    tar = a[x]
    l = 0
    r = x
    best_l = x
    while l <= r:
        mid = (l + r) // 2
        length = x - mid + 1
        cost = length * tar - prefix[x + 1] + prefix[mid]
        if cost <= k:
            best_l = mid
            r = mid - 1
        else:
            l = mid + 1
    cur = x - best_l + 1
    if cur > max_cnt:
        max_cnt = cur
        best = tar
print(max_cnt, best)
