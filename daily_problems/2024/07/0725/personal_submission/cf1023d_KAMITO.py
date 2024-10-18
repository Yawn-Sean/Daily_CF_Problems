def solve():
    n,q=map(int,input().split())
    a=list(map(int,input().split()))

    if q not in a and 0 not in a:
        print('NO')
        return
    if a.count(0)==n:
        print('YES')
        print(*[q]*n)
        return

    for i in range(n):
        if a[i]==0:
            a[i]=inf

    def init():
        for j in range(M):
            i=0
            while i+(1<<j)-1<n:
                if not j:
                    f[i][j]=a[i]
                else:
                    f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1])
                i+=1
        return

    def query(l,r):
        k=LOG2[r-l+1]
        x=min(f[l][k],f[r-(1<<k)+1][k])
        return x

    M=18
    LOG2=[-1]*(n+1)
    f=[[0]*M for i in range(n)]
    for i in range(1,n+1):
        LOG2[i]=LOG2[i>>1]+1
    init()

    L=[-1]*(q+1);R=[-1]*(q+1)
    for i in range(n):
        if a[i]==inf:
            continue
        R[a[i]]=i
        if L[a[i]]==-1:
            L[a[i]]=i

    for i in range(q,0,-1):
        l,r=L[i],R[i]
        if l==-1:
            if i==q:
                for j in range(n):
                    if a[j]==inf:
                        a[j]=i
                        break
            continue
        x=query(l,r)
        if x<i:
            print('NO')
            return
    for i in range(n):
        if a[i]!=inf:
            for j in range(i-1,-1,-1):
                a[j]=a[j+1]
            break
    for i in range(n):
        if a[i]==inf:
            a[i]=a[i-1]
    print('YES')
    print(*a)




    return


test=1
# test=int(input())
for _ in range(test):
    solve()
