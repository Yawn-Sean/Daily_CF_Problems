for _ in range(int(input())):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    max_a=max(a)
    min_a=min(a)
    t1=a.index(max_a)
    t2=a.index(min_a)
    cnt=0
    for i in range(n-1):
        cnt+=abs(a[i]-a[i+1])
    if max_a>=m:
        if min_a<=1:
            print(cnt)
        else:
            print(min(a[0]-1,a[-1]-1,(min_a-1)*2)+cnt)
    else:
        if min_a<=1:
            print(min(m-a[0],m-a[-1],(m-max_a)*2)+cnt)
        else:
            print(min((m-max_a)*2+(min_a-1)*2,m-a[0]+a[-1]-1
                      ,a[0]-1+m-a[-1],a[0]-1+(m-max_a)*2,a[-1]-1+(m-max_a)*2,
                      m-a[0]+(min_a-1)*2,m-a[-1]+(min_a-1)*2)+cnt)
