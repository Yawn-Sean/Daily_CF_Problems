import sys
import bisect
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
b=LII()
ls=[]
for i in range(n):
    if a[i]>b[i]:
        ls.append(a[i])
        ls.append(b[i])
    else:
        ls.append(b[i])
        ls.append(a[i])
dp=[]
for x in ls:
    idx=bisect.bisect_left(dp,x)
    if idx==len(dp):
        dp.append(x)
    else:
        dp[idx]=x
print(len(dp))