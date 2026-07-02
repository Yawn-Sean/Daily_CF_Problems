import sys
input=sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int,input().split()))
t=II()
for _ in range(t):
    n=II()
    neg=0
    pos=0
    zero=0
    for i in range(n):
        x,y=LII()
        diff=x-y
        if diff<0:
            neg+=1
        elif diff>0:
            pos+=1
        else:
            zero+=1
    ans=neg*pos+zero*(neg+pos)+zero*(zero-1)//2
    print(ans)
