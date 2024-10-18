import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

n = int(input())
a = sorted(list(map(float, input().split())), reverse = True)
ans, p0, p1 = 0, 1, 0
for ai in a:
    p1 = p1 * (1 - ai) + p0 * ai
    p0 *= 1 - ai
    ans = max(ans, p1)
print(ans)
