import sys
input = sys.stdin.readline
def II():
    return int(input())
t=II()
for _ in range(t):
    n=II()
    k=(n+1)//2
    l=1
    h=k-1
    while l<h:
        mid=(l+h)//2
        print(1,2*mid,flush=True)
        a=II()
        print(2,2*mid+1,flush=True)
        b=II()
        if a==b:
            h=mid
        else:
            l=mid+1
    print(3,2*l-1,2*l+1,flush=True)