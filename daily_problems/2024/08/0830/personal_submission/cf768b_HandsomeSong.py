import sys
input=sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int,input().split()))
n,l,r=LII()
ans=0
for i in range(l,r+1):
    x=n
    pos=i
    while x>1:
        L=(1<<x.bit_length())-1
        mid=L//2+1
        if pos==mid:
            break
        elif pos<mid:
            x>>=1
        else:
            x>>=1
            pos-=mid
    ans+=x&1
print(ans)
