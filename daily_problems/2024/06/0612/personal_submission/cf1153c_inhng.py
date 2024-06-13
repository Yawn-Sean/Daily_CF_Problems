import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n = int(input())
s = list(input())
cnt, cur = n // 2 - s.count('('), 0
for i in range(n):
    if s[i] == '(':
        cur += 1
    elif s[i] == ')':
        cur -= 1
    elif cnt:
        s[i] = '('
        cur += 1
        cnt -= 1
    else:
        s[i] = ')'
        cur -= 1
    if cur <= 0 and i != n - 1:
        exit(print(':('))
else:
    print(''.join(s) if cur == 0 else ':(')
