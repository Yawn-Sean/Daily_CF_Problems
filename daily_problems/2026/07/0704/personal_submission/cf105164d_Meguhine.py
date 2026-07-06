MOD = 10**9 + 7
n = int(input())
ans = 0
for x in range(1, n):
    yz = n - x * 3
    if yz < 0:
        break
    y_pivot = (yz - x) // 2 + 1
    if y_pivot >= 0:
        ans += x * y_pivot
    else:
        y_pivot = 0
    y_mx = yz // 2
    ans += (yz + 1) * (y_mx - y_pivot + 1)
    ans -= (y_pivot + y_mx) * (y_mx - y_pivot + 1)
print(ans)
