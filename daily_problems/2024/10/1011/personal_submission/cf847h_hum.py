n = int(input())
a = list(map(int, input().split()))
pre = [0] * n
v_pre = [0] * n
suf = [0] * n
v_suf = [0] * n

v_pre[0] = a[0]
v_suf[-1] = a[-1]

for i in range(1, n):
  v_pre[i] = max(a[i], v_pre[i - 1] + 1)
  pre[i] = pre[i - 1] + v_pre[i] - a[i]

for i in range(n - 2, -1, -1):
  v_suf[i] = max(a[i], v_suf[i + 1] + 1)
  suf[i] = suf[i + 1] + v_suf[i] - a[i]

res = min(pre[-1], suf[0])
for i in range(n - 1):
  res = min(res, pre[i - 1] + suf[i + 1] + max(v_pre[i], v_suf[i]) - a[i])

print(res)
