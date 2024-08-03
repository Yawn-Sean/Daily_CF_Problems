import sys
input = sys.stdin.readline
mod = 10 ** 9 + 7 # 998244353

n, m = map(int, input().split())
a = sorted(list(map(int, input().split())))
b = sorted(list(map(int, input().split())), reverse = True)
i = ans = 0
while i < min(n, m) and a[i] < b[i]:
    ans += b[i] - a[i]
    i += 1
print(ans)
