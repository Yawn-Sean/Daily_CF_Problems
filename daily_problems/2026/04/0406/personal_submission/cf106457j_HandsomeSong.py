import bisect
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,q=MII()
lsl=[]
lsr=[]
ls=[]
for _ in range(n):
    a,b=MII()
    lsl.append(a)
    lsr.append(b)
    ls.append(a)
    ls.append(b+1)
ls.sort()
diff=[0]*2*n
acc=[0]*2*n
for i in range(n):
    diff[bisect.bisect_left(ls,lsl[i])]+=1
    diff[bisect.bisect_left(ls,lsr[i]+1)]-=1
for i in range(1,2*n):
    diff[i]+=diff[i-1]
for i in range(2*n-1):
    acc[i+1]=acc[i]+diff[i]*(ls[i+1]-ls[i])
x=LII()
for xx in x:
    xx-=1
    p=bisect.bisect_right(acc,xx)-1
    ans=ls[p]+(xx-acc[p])//diff[p]
    print(ans)
