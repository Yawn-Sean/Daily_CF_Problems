l=[]
import math
def solve():
    n=int(input())
    a=list(map(int,input().split()))
    h=max(a)
    x=1
    y=1000000000
    for i in range(n-1):
        if abs(a[i+1]-a[i])>1:
            x=abs(a[i+1]-a[i])
            if i:
                max_=max(a[:i+1:])
                min_=min(a[:i+1:])
                m1=max_//x
                m2=min_//x
                if max_%x:
                    m1+=1
                if min_%x:
                    m2+=1

                if m1!=m2:
                
                    return False
            break
    if x==1:
        x=y
    l.append(x)
    l.append(y)
    tar=a[0]
    for i in range(1,n):
        if (tar-1)%x==0:
            if a[i]not in [tar-x,tar+x,tar+1]:
                return False
        if tar%x==0:
            if a[i]not in [tar-x,tar+x,tar-1]:
                return False
        if abs(a[i]-tar)==1 or abs(a[i]-tar)==x:
            tar=a[i]
        else:
            return False
    return True
if solve():
    print("YES")
    print(*l[::-1])
else:
    print("NO")
