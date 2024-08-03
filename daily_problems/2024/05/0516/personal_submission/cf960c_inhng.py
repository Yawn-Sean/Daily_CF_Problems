import sys
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

x, d = map(int, input().split())
ans = []
num, cnt = 1, 0
for i in range(60, 0, -1):
    if (x >> i) & 1:
        ans.extend(num for _ in range(i))
        cnt += 1
        num += d + 1
for _ in range(cnt):
    ans.append(num)
    num += d + 1
if x & 1:
    ans.append(num)
print(len(ans))
print(*ans)
