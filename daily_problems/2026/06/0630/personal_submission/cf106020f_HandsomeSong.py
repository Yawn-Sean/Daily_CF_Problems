import sys
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,k=MII()
a=LII()
odd=[]
even=[]
for i in range(n):
    idx=i+1
    if idx%2==1:
        odd.append((a[i],idx))
    else:
        even.append((a[i],idx))
odd.sort(key=lambda x:x[0],reverse=True)
even.sort(key=lambda x:x[0],reverse=True)
used=[False]*(n+1)
po=0
pe=0
lo=len(odd)
le=len(even)
r=k
for _ in range(k):
    x=II()
    if x==2:
        while pe<le and used[even[pe][1]]:
            pe+=1
        val,idx=even[pe]
        pe+=1
        used[idx]=True
        sys.stdout.write(str(idx)+"\n")
        sys.stdout.flush()
        r-=1
    else:
        while po<lo and used[odd[po][1]]:
            po+=1
        while pe<le and used[even[pe][1]]:
            pe+=1
        er_idx=pe+r-1
        if po<lo and odd[po][0]>=even[er_idx][0]:
            val,idx=odd[po]
            po+=1
        else:
            val,idx=even[pe]
            pe+=1
        used[idx]=True
        print(idx,flush=True)
        r-=1
    res=II()
    if res==0:
        sys.exit(0)