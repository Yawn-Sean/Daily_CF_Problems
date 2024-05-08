from math import isqrt
from collections import Counter

def to_base(num, base):
    ret = []
    while num:
        ret.append(str(num % base))
        num //= base
    return " ".join(ret[::-1])

def factorise(num):
    ret = Counter()
    def helper(num):
        if num == 1:
            return
        for i in range(2, isqrt(num) + 1):
            if num % i == 0:
                ret[i] += 1
                helper(num // i)
                break
        else:
            ret[num] += 1
    helper(num)
    return ret

n, b = list(map(int, input().split(" ")))
ans = float("inf")
for factor, freq in factorise(b).items():
    t = n
    temp = 0
    k = n // factor
    while t:
        temp += t // factor
        t //= factor
    ans = min(ans, temp // freq)
print(ans)


