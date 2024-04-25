import sys
from collections import defaultdict
from math import inf

RII = lambda: map(int, sys.stdin.readline().strip().split())

n, b = RII()

# 对b分解质因数,记录每个质因数出现的次数
primes = defaultdict(int)
d = 2
while d * d <= b:
    if b % d == 0:
        cnt = 0
        while b % d == 0:
            b //= d
            cnt += 1
        primes[d] = cnt
    d += 1
if b > 1:
    primes[b] = 1


# 计算n！中包含p的个数,这里注意要用n不断除p，用p不断乘p会溢出
def get_cnt(n, p):
    cnt = 0
    while n:
        cnt += n // p
        n //= p
    return cnt


ans = inf
for k, v in primes.items():
    ans = min(ans, get_cnt(n, k) // v)
print(ans)
