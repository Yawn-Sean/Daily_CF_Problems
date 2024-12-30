import sys
input = lambda: sys.stdin.readline().strip()
from collections import Counter
mod = 10 ** 9 + 7 # 998244353

n, k = map(int, input().split())
a = list(map(int, input().split()))
mp = Counter()
for ai in a:
    for i in range(k + 1):
        mp[ai * i] = i

for _ in range(int(input())):
    x = int(input())
    ans = k + 1
    for i in mp:
        if (x - i) in mp:
            ans = min(ans, mp[i] + mp[x - i])
    print(-1 if ans > k else ans)
