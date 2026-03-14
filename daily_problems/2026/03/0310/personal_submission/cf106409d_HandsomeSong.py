n,m=map(int,input().split())
arr=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split())
    arr[u].append(v)
    arr[v].append(u)
if n<4 or m<3:
    print(-1)
    exit()
for i in range(n+1):
    for j in arr[i]:
        for k in arr[i][:3]:
            for l in arr[j][:3]:
                if k!=j and l!=i and k!=l:
                    print(k,i,j,l,sep='\n')
                    exit()
print(-1)