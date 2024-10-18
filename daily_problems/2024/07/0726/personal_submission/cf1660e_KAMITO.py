from math import inf
def solve():
    t=input()
    n=int(input())
    a=[]
    for i in range(n):
        a.append(input())
    cnt=[];s=0
    for i in range(n):
        c=0
        for j in range(n):
            c+=int(a[j%n][(i+j)%n])
        s+=c
        cnt.append(c)
    ans=inf
    for i in range(n):
        ans=min(ans,n-cnt[i]+s-cnt[i])
    print(ans)


    return


test=1
test=int(input())
for _ in range(test):
    solve()
