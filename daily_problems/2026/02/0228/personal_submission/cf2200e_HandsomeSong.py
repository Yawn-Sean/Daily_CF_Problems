def II():
    return int(input())
def LII():
    return list(map(int, input().split()))

M=10**6
p=list(range(M+1))
cnt=[0]*(M+1)

for i in range(2,M+1):
    if p[i]==i:
        for j in range(i,M+1,i):
            p[j]=i
            cnt[j]+=1


t=II()
for _ in range(t):
    n=II()
    a=LII()
    if sorted(a)==a:
        print('Bob')
    else:
        flg=False
        for i in range(n):
            if cnt[a[i]]>1:
                flg=True
            a[i]=p[a[i]]
        if flg:print('Alice')
        else: print('Bob')