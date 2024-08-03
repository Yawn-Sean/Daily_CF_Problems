from math import inf
n, b = map(int, input().split())

def primes(x):
    dic = {}
    for i in range(2, x):
        if i ** 2 > x:
            break
        if not x % i:
            dic[i] = 0
            while x and not x % i:
                dic[i] += 1
                x //= i
    if x > 1:
        dic[x] = 1
    return dic

dic = primes(b)
ans = inf
for i in dic:
    cnt = 0
    k = i
    while n // k != 0:
        cnt += n // k
        k *= i
    ans = min(ans, cnt // dic[i])

print(ans)
        
