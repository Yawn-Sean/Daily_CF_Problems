# -*- coding : utf-8 -*-
import sys

input = lambda: sys.stdin.readline().rstrip()
# sys.stdin = open('../input.txt', 'r')
# sys.stdout = open('../output.txt', 'w')
I = lambda: int(input())

tcn = I()
for _tcn_ in range(tcn):
    s = input()
    n = len(s)
    ans = s.count('1') + s.count('10')
    left_zero = 0
    for i in range(n):
        if s[i] == '0':
            left_zero += 1
        elif left_zero:
            x = 0
            for j in range(i, n):
                x *= 2
                x += int(s[j])
                if left_zero >= x - (j - i + 1):
                    if x - (j - i + 1) > 0:
                        ans += 1
                else:
                    break
            left_zero = 0
    print(ans)
