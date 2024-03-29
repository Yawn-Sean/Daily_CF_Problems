n = int(input())
arr = list(map(int, input().split()))
ans = n
if 1 in arr:
    print(n - arr.count(1))
    exit(0)
for i in range(n):
    g = arr[i]
    for j in range(i, n):
        g = gcd(g, arr[j])
        if g == 1:
            ans = min(ans, j - i)
            break
print(ans + n - 1 if ans < n else -1)
