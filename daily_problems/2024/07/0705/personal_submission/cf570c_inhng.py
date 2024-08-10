import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n, m = map(int, input().split())
s = ['/'] + list(input()) + ['/']
cnt = ans = 0
for i in range(1, n + 1):
    if s[i] == '.':
        cnt += 1
    else:
        ans += max(0, cnt - 1)
        cnt = 0
ans += max(0, cnt - 1)
for _ in range(m):
    x, c = map(str, input().split())
    x = int(x)
    if s[x] != '.' and c == '.':
        ans += (s[x - 1] == '.') + (s[x + 1] == '.')
    elif s[x] == '.' and c != '.':
        ans -= (s[x - 1] == '.') + (s[x + 1] == '.')
    s[x] = c
    print(ans)
