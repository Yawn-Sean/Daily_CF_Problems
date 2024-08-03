n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a.sort()
b.sort(reverse = True)
ans = 0
for i in range(min(n, m)):
    if a[i] < b[i]:
        ans += b[i] - a[i]
print(ans)
