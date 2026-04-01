n, m = map(int, input().split())

a = [0] + sorted(list(map(int, input().split())))

for i in range(1, n + 1):
    a.append(a[i] + m)

s = [0] * (n + n + 1)
for i in range(1, n + n + 1):
    s[i] = s[i - 1] + a[i]

def rsum(l, r):
    return s[r] - s[l - 1]

ans = 10 ** 18

for i in range(1, n + 1):
    l, r = i, i + n - 1
    mid = (l + r) // 2
    now = a[mid] * (mid - l + 1) - rsum(l, mid) + rsum(mid, r) - a[mid] * (r - mid + 1)
    ans = min(ans, now)

print(ans)
