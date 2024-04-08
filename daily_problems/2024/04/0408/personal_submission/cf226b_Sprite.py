from functools import cache
from itertools import accumulate
n = int(input())
a = list(map(int, input().split()))
a.sort(reverse = True)
presum_a = list(accumulate(a))

@cache
def f(k):
    if n == 1:
        return 0
    ans, i, last, k_ = 0, 1, 0, k
    while last != n-1:
        nxt = last + k_
        if nxt > n-1:
            nxt = n-1
        now = presum_a[nxt] - presum_a[last]
        ans += now * i
        i += 1
        last = nxt
        k_ *= k
    return ans

q = int(input())
k = list(map(int, input().split()))
ans = []
for i in range(q):
    ans.append(f(k[i]))
print(*ans)
