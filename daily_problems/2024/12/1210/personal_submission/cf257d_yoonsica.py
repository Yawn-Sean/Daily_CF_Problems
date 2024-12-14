import sys
from math import inf

standard_input = True
if standard_input:
    RI = lambda: int(sys.stdin.readline().strip())
    RF = lambda: float(sys.stdin.readline().strip())
    RS = lambda: sys.stdin.readline().strip()
    RFF = lambda: map(float, sys.stdin.readline().strip().split())
    RII = lambda: map(int, sys.stdin.readline().strip().split())
    RILIST = lambda: list(RII())
    RFLIST = lambda: list(RFF())

else:
    fin = open('input.txt', 'r')
    fout = open('output.txt', 'w')
    input = lambda: fin.readline().strip()
    RI = lambda: int(input())
    RF = lambda: float(input())
    RS = lambda: input()
    RFF = lambda: map(float, input())
    RII = lambda: map(int, input().split())
    RILIST = lambda: list(RII())
    RFLIST = lambda: list(RFF())
    
    
    def print(x):
        fout.write(str(x))

mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

n = RI()
a = RILIST()
s = a[-1]
ans = [0] * n
# 1 2 3 5 保持abs(s) <= a[i]
for i in range(n - 2, -1, -1):
    if abs(s + a[i]) > a[i]:
        s -= a[i]
        ans[i] = 1
    else:
        s += a[i]
if s < 0:
    ans = [1 if x == 0 else 0 for x in ans]
print(''.join(map(str, ['+' if x == 0 else '-' for x in ans])))
