import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()
mod = 10 ** 9 + 7 # 998244353

def f(n, x):
    ans = 0
    while n:
        n //= x
        ans += n
    return ans

n, b = map(int, input().split())
i, ans = 2, 0x3f3f3f3f3f3f3f3f
primes = []
mp = Counter()
while i * i <= b:
    if b % i == 0:
        primes.append(i)
        while b % i == 0:
            mp[i] += 1
            b //= i
    i += 1
if b > 1:
    mp[b] += 1
    primes.append(b)
for prime in primes:
    ans = min(ans, f(n, prime) // mp[prime])
print(ans)
