# Submission link: https://codeforces.com/gym/106035/submission/352541084
import math
n,m,k=list(map(int,input().split()))

x=abs(n-m)
def Func(x):
    ret=0
    while x:
        x&=(x-1)
        ret+=1
    return ret
if x>=k:
    ans=0
    for i in range(k+1):
        ans+=Func(math.comb(k,i))
    print(ans)
else:
    S=0
    for i in range(k+1):
        S+=math.comb(k,i)<<(x*i)
    print(Func(S))