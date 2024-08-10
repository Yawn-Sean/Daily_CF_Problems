#https://codeforces.com/problemset/problem/1009/E
#贡献法，考虑每一位对结果的贡献
import sys
from collections import *
from math import *
iput = lambda:sys.stdin.readline().rstrip()
RI = lambda:int(sys.stdin.readline().rstrip())
RII = lambda:map(int,sys.stdin.readline().rstrip().split())
RIII = lambda : sys.stdin.readline().rstrip().split()
RLIST = lambda:list(map(int,sys.stdin.readline().rstrip().split()))
n = RI()
a = RLIST()
#ai * 2^(n-i) + (n-i) * ai * 2 ^ (n-i-1) i从1开始
mod = 998244353
ans = 0
li = [1] * (n)
for i in range(1,n):
    li[i] = li[i-1] * 2 % mod
for i in range(1,n+1):
    ans += a[i-1] * (li[n-i] + (n-i) * li[n-i-1]) % mod
    ans %= mod
print(int(ans))
