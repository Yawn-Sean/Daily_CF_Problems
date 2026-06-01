import sys
input = sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int, input().split())
def ask(idx):
    print('?',len(idx),*idx,flush=True)
    _,*res=MII()
    return(res)
def answer(ans):
    print('!',' '.join(f'{len(v)} {" ".join(map(str,v))}' for v in ans))
n=II()
ans=[[]for _ in range(n)]
if n==1:
    res=ask([1])
    ans[0]=res
else:
    k=n//2
    batch1=[]
    for i in range(1,k+1):
        batch1+=[i,i]
    res1=ask(batch1)
    pos=0
    for i in range(1,k+1):
        p=1
        while res1[pos:pos+p]!=res1[pos+p:pos+2*p]:
            p+=1
        ans[i-1]=res1[pos:pos+p]
        pos+=2*p
    batch2=[]
    for i in range(k+1,n):
        batch2+=[i,i]
    batch2.append(n)
    res2=ask(batch2)
    pos=0
    for i in range(k+1,n):
        p=1
        while res2[pos:pos+p]!=res2[pos+p:pos+2*p]:
            p+=1
        ans[i-1]=res2[pos:pos+p]
        pos+=2*p
    ans[n-1]=res2[pos:]
answer(ans)