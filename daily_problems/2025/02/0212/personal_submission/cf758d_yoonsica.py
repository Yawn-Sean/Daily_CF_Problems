import sys
from math import inf

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/758/D

m进制下的字符串s中ABCD....可能用10，11，12...表示，求该字符串转换成10进制的最小值，

分析：
n = len(s)
考虑dp
f = [inf] * (n + 1)
f[0] = 0
# 考虑m最多用多少位表示，m.bit_length() 最多36左右
f[i] = f[j] * m + int(s[j + 1:i])
注意s[j:i]不能有前导0
'''
m, s = RI(), RS()
n = len(s)
f = [inf] * (n + 1)
f[0] = 0
b = m.bit_length()
for i in range(1, n + 1):
    # i - j + 1 == b
    for j in range(i, 0, -1):
        if i - j + 1 > b or int(s[j - 1: i]) >= m:
            break
        if j < i and s[j - 1] == '0':
            continue
        t = int(s[j - 1: i])
        f[i] = mn(f[i], f[j - 1] * m + int(s[j - 1: i]))
print(f[-1])