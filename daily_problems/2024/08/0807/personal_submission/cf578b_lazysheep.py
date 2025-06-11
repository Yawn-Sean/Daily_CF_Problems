n, k, v = map(int, input().split())
a = list(map(int, input().split()))
pre = [0] * (n + 1)
suf = [0] * (n + 1)
for i, x in enumerate(a):
    pre[i + 1] = pre[i] | x 
for i in range(n - 1, -1, -1):
    suf[i] = suf[i + 1] | a[i]
 
ans = 0
for i, x in enumerate(a):
    x *= v ** k
    res = pre[i] | x | suf[i + 1]
    ans = max(ans, res)
   
