def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
    
t=II()
for _ in range(t):
    n=II()
    a=LII()
    for i in range(n-1):
        if a[i]>=a[i+1]:
            print(a[i]//(a[i+1]-1))
            break    
    else:
        line=a[1]-a[0]
        col=a[-1]//(a[1]-a[0])
        print(max(line,col))

