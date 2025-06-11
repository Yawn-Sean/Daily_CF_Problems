# import sys

# sys.stdin = open('in.txt','r')
mod = 998244353

n = int(input())
a = list(map(int, input().split()))

a.sort()

f = [0] * 5001
f[0] = 1

res = s = 0
for x in a:
    for i in range(s, -1, -1):
        if f[i]:
            res = (res + f[i] * max((i + x + 1) // 2, x)) % mod
            f[i + x] = (f[i] + f[i + x ]) % mod
    s += x

print(res)