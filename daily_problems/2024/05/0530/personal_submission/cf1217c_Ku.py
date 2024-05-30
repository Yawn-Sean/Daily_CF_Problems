#https://codeforces.com/problemset/problem/1217/C
import sys
iput = lambda:sys.stdin.readline().rstrip()

RI = lambda:int(sys.stdin.readline().rstrip())
RII = lambda:map(int,sys.stdin.readline().rstrip().split())
RLIST = lambda:list(map(int,sys.stdin.readline().rstrip().split()))
t = RI()
ans = []
for _ in range(t):
    pre_0 = [0]
    s = input()
    n = len(s)
    for c in s:
        if c == '0':
            pre_0.append(pre_0[-1] + 1)
        else:
            pre_0.append(0)
    cnt = 0
    for i in range(n):
        res = 0
        for j in range(i,max(0,i-32)-1,-1):
            #枚举的长度不会太长，否则二进制数>10**9
            if s[j] == '1':
                res |= (1 << (i-j))
                if i - j + 1 + pre_0[j] >= res:
                    cnt += 1
    ans.append(cnt)
print(len(ans))
print('\n'.join(map(str,ans)))
