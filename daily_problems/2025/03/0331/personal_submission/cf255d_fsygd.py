def solve(n, x, y, k):
    stubs = [x]
    if x - k >= 1:
        stubs.append(x - k)
    else:
        stubs.append(1)
    if y - k < 1 and x + y - 1 - k >= 1:
        stubs.append(x + y - 1 - k)
    if y + k > n and x + n - y - k >= 1:
        stubs.append(x + n - y - k)
    stubs = sorted(list(set(stubs)))
    ans = 0
    for i in range(len(stubs) - 1):
        x1 = stubs[i]
        x2 = stubs[i + 1] - 1
        l1 = min(n, y + k - (x - x1)) - max(1, y - k + (x - x1)) + 1
        l2 = min(n, y + k - (x - x2)) - max(1, y - k + (x - x2)) + 1
        ans += (l1 + l2) * (x2 - x1 + 1) / 2
    return ans

n, x, y, c = list(map(int, input().split(' ')))
l, r = 0, n * 2
while l < r:
    mid = (l + r) // 2
    if solve(n, x, y, mid) + solve(n, n - x + 1, y, mid) + (min(n, y + mid) - max(1, y - mid) + 1) >= c:
        r = mid
    else:
        l = mid + 1
print(l)