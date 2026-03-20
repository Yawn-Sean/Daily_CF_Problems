n=int(input())
if n %4==3:
    print(-1)
else:
    res=list(range(1,n+1))
    for i in range(3,n,4):
        res[i-1],res[i]=res[i],res[i-1]
    print(*res)