import sys
from functools import cache
from collections import Counter
sys.stdin = open('in.txt','r')

s = input()
n = len(s)
def get(i: int, j: int) -> int:
    return i * n + j

f = [0] * (n * n)

for i in range(n):
    f[get(i, i)] = 1

for slen in range(2, n + 1):
    for i in range(n + 1 - slen):
        j = i + slen - 1
        if s[i] == s[j] and (slen == 2 or f[get(i + 1, j - 1)]):
            f[get(i, j)] = f[get(i, i + slen // 2 - 1)] + 1

cnt = [0] * (n + 1)

for i in range(n):
    for j in range(i, n):
        cnt[f[get(i, j)]] += 1
for i in range(n, 0, -1):
    cnt[i - 1] += cnt[i]
print(' '.join(map(str, cnt[1::])))