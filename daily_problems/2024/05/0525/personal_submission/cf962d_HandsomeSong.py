import heapq
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
    
n=II()
a=LII()
h=[a[i]*n+i for i in range(n)]
heapq.heapify(h)
ans=[-1]*n
while h:
    x1,i1=divmod(heapq.heappop(h),n)
    if h and h[0]//n==x1:
        i2=heapq.heappop(h)%n
        x1*=2
        heapq.heappush(h,x1*n+i2)
    else:
        ans[i1]=x1
ans=[str(x)for x in ans if x !=-1]
print(len(ans))
print(' '.join(ans))