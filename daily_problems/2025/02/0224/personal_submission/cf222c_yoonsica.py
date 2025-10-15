import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/222/C
给出两个集合，第一个集合数的乘积是分子，第二个集合的数的乘积是分母，要求构造一个同样的集合，但是得到的分数是最简分数。

记录上下需要约分掉的质因子
'''
n, m = RII()
a, b = RILIST(), RILIST()
N = 10 ** 7 + 1

# 线性筛
factors = list(range(N)) # 记录i是被谁筛的
primes = []
for i in range(2, N):
    if factors[i] == i:
        primes.append(i)
    for p in primes:
        if i * p >= N:
            break
        factors[i * p] = p
        if i % p == 0:
            break

cnt1, cnt2 = [0] * N, [0] * N
for x in a:
    while x > 1:
        cnt1[factors[x]] += 1
        x //= factors[x]

for x in b:
    while x > 1:
        cnt2[factors[x]] += 1
        x //= factors[x]
        
for i in range(1, N):
    cnt1[i] = mn(cnt1[i], cnt2[i]) # 这些需要被约分
    cnt2[i] = cnt1[i]
    
for i, x in enumerate(a):
    while x > 1:
        if cnt1[factors[x]]:
            cnt1[factors[x]] -= 1
            a[i] //= factors[x]
        x //= factors[x]

for i, x in enumerate(b):
    while x > 1:
        if cnt2[factors[x]]:
            cnt2[factors[x]] -= 1
            b[i] //= factors[x]
        x //= factors[x]
        
print(n, m)
print(*a)
print(*b)
