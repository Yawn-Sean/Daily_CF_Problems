# https://codeforces.com/contest/351/submission/272035050
n = RI()
s = 0  # 原数组和
cnt = 0  # 整数个数
s2 = 0  # 小数和
for x in RS().split():
    s += float(x)
    a, b = x.split('.')
    if b == '000':
        cnt += 1
    s2 += float(x) - int(a)
ans = inf
# 枚举n个数里面整数个数
for i in range(min(cnt, n) + 1):
    ans = min(ans, abs(s - (s + n - i - s2)))
print('{:.3f}'.format(ans))