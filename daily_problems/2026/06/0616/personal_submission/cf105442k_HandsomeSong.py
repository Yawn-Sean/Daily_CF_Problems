import sys
input = sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int, input().split())
n=II()
ans=10**18
for i in range(n):
    a,b,c,d,e=MII()
    b_a=b-a
    e_d=e-d
    if b_a>=0 and e_d>=0:
        ans=min(ans,a+d)
    elif b_a<0 and e_d<0:
        ans=min(ans,b+e)
    else:
        if b_a>0:
            b_a,e_d=e_d,b_a
            a,b,d,e=d,e,a,b
        c=min(c,-b_a,e_d)
        ans=min(ans,d+c+b)
print(ans)