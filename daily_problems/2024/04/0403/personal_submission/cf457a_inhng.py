import sys
input = sys.stdin.readline
mod = 10 ** 9 + 7 # 998244353

a = input().strip()
b = input().strip()
n = max(len(a), len(b))
a = '0' * (n - len(a)) + a
b = '0' * (n - len(b)) + b
x = y = 0
for i in range(n):
    x, y = x + y, x + int(a[i]) - int(b[i])
    if x > 1:
        exit(print('>'))
    elif x < -1:
        exit(print('<'))
if x == y == 0:
    print('=')
else:
    while abs(x) < 2:
        x, y = x + y, x
    print('>' if x > 1 else '<')
