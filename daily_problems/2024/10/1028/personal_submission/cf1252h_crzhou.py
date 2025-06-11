n = II()
ls = []
for i in range(n):
    a, b = MII()
    if a > b:
        a, b = b, a
    ls.append((a, b))

ans = 0

ls.sort(reverse=True)
mx = 0
for a, b in ls:
    ans = fmax(ans, a * b)
    ans = fmax(ans, a * min(b, mx) * 2)
    if b > mx:
        mx = b
    
print(f'{ans // 2}.{ans % 2 * 5}')
