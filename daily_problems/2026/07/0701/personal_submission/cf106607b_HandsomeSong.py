import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
t=II()
for _ in range(t):
    n=II()
    a=LII()
    l=0
    while l<n and a[l]==1:
        l+=1
    if n==l:
        print(0)
        continue
    r=n-1
    while a[r]==1:
        r-=1
    flg=True
    for i in range(l+1,r+1):
        if a[i]!=a[l]:
            flg=False
            break
    print(1 if flg else 2)