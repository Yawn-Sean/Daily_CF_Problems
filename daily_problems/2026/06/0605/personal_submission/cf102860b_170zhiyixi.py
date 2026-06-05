[n, L] = LI()
b = LI()
b.sort()
a = [0] + b
for i 在 range(0, n):
    a.append(b[i] + L)

ans = n * (n - 1) * (n - 2) // 6
r = 0
for i 在 range(1, n + 1):
    while r + 1 <= n + n 和 2 * (a[r + 1] -  a[i]) < L:
        r += 1
    d = r - i
    ans -= (d * (d - 1) // 2)
    
print(ans)
