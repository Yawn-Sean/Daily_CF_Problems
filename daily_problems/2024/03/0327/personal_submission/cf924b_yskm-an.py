n, u = map(int, input().split())
arr = list(map(int, input().split()))
i = 0
j = 2
res = -1
while i < n - 2:
    while j < n and arr[j] - arr[i] <= u:
        j += 1
    if j - i < 3:
        j = i + 3
    k = arr[j - 1]
    l = arr[i]
    r = arr[i + 1]
    if k - l <= u:
        res = max(res, (k - r) / (k - l))
    i += 1

print(res)
