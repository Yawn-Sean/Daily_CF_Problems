# -*- coding: utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
sys.stdin = open('../input.txt', 'r')
I = lambda: int(input())
MI = lambda: map(int, input().split())
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LI = lambda: list(MI())
LGMI = lambda: list(GMI())
YN = lambda x: print('YES' if x else 'NO')
mod = 1000000007
mod2 = 998244353

t1 = list(int(c) for c in input())
t2 = list(int(c) for c in input())
t1.reverse()
t2.reverse()


def get_sum(s):
    ss = []
    cnt = 0
    for x in s:
        if x == 1:
            cnt += 1
        else:
            if cnt == 1:
                ss.append('10')
                cnt = 0
            elif cnt == 0:
                ss.append('0')
                cnt = 0
            else:
                if cnt % 2 == 0:
                    ss.append('00' + '10' * (cnt // 2 - 1))
                else:
                    ss.append('100' + '10' * (cnt // 2 - 1))
                cnt = 1
    if cnt == 1:
        ss.append('1')
    elif cnt == 0:
        ss.append('0')
    else:
        if cnt % 2 == 0:
            ss.append('00' + '10' * (cnt // 2 - 1))
        else:
            ss.append('100' + '10' * (cnt // 2 - 1))
        ss.append('1')
    return ''.join(ss)


s1 = get_sum(t1)
s2 = get_sum(t2)
s1 = s1[::-1]
s2 = s2[::-1]
n = max(len(s1), len(s2))
s1 = '0' * (n - len(s1)) + s1
s2 = '0' * (n - len(s2)) + s2
# print(s1)
# print(s2)
if s1 == s2:
    print('=')
elif s1 < s2:
    print('<')
else:
    print('>')
