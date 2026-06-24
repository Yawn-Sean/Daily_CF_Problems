import sys
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,q=MII()
a=LII()
freq=[0]*(10**6+1)
for i in a:
    freq[i]+=1
mx=n
div=[[] for _ in range(mx+1)]
for i in range(1,mx+1):
    for j in range(i,mx+1,i):
        div[j].append(i)
ans=[0]*1000001
for c in set(a):
    f=freq[c]
    if f>0:
        for d in div[f]:
            ans[d]+=1
for _ in range(q):
    quire=LII()
    if quire[0]==1:
        old=a[quire[1]-1]
        new=quire[2]
        if old!=new:
            f_old=freq[old]
            for d in div[f_old]:
                ans[d]-=1
            f_new=f_old-1
            freq[old]=f_new
            if f_new>0:
                for d in div[f_new]:
                    ans[d]+=1
            f_old=freq[new]
            if f_old > 0:
                for d in div[f_old]:
                    ans[d]-=1
            f_new=f_old+1
            freq[new]=f_new
            for d in div[f_new]:
                ans[d]+=1
            a[quire[1]-1]= new
    else:
        x=quire[1]
        if x>mx:
            print(0)
        else:
            print(ans[x])