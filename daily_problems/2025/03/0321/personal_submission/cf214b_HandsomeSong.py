import sys
input=sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int,input().split()))
n=II()
a=LII()
if 0 not in a:
    print(-1)
    exit()
a.sort(reverse=True)
def out():
    if a[0]==0:
        print(0)
    else:
        print(''.join(map(str,a)))
    exit()
f=sum(a)%3
if f==0:
    out()
if f==1:
    i=n
    while i>0:
        i-=1
        if a[i]%3==1:
            a.pop(i)
            out()
    i=n
    cnt=0
    while i>0:
        i-=1
        if a[i]%3==2:
            cnt+=1
            if cnt==1:
                d=i
            elif cnt==2:
                a.pop(d)
                a.pop(i)
                out()
else:
    i=n
    while i>0:
        i-=1
        if a[i]%3==2:
            a.pop(i)
            out()
    i=n
    cnt=0
    while i>0:
        i-=1
        if a[i]%3==1:
            cnt+=1
            if cnt==1:
                d=i
            elif cnt==2:
                a.pop(d)
                a.pop(i)
                out()
print(-1)