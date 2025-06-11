#https://codeforces.com/problemset/problem/1153/C
import sys
iput = lambda:sys.stdin.readline().rstrip()
RI = lambda:int(sys.stdin.readline().rstrip())
RII = lambda:map(int,sys.stdin.readline().rstrip().split())
RLIST = lambda:list(map(int,sys.stdin.readline().rstrip().split()))

n = RI()
s = list(input())

opt = n // 2 - s.count('(')  #剩余（个数
if n % 2 or opt < 0:
    print(':(')
    exit()
res = 0
for i,x in enumerate(s):
    if x == '(':
        res += 1
    elif x == ')':
        res -= 1
    elif opt:
        s[i] = '('
        res += 1
        opt -= 1
    else:
        s[i] = ')'
        res -= 1
    if res < 0 or (res == 0 and i != n - 1):
        print(':(')
        exit()

print(''.join(s))
