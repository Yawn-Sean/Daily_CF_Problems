n, u = map(int, input().split())
e = list(map(int, input().split()))
ans = -1
k = 2
for i in range(n-2):
    j = i+1
    while k+1 < n and e[k+1] - e[i] <= u:
        k += 1
    if k > j and e[k] - e[i] <= u:
        ans = max(ans, (e[k] - e[j]) / (e[k] - e[i]))
print(ans)
