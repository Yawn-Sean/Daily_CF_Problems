def solve():
    n=II()
    a=LMIIS()
    cnt=defaultdict(list)
    rnd=randint(int(1e9),int(1e10))
    for i in range(n):
        cnt[a[i]^rnd].append(i+1)
    ans=[]
    m=0
    for i in range(n):
        while m>=0 and not cnt[m^rnd]:
            m-=3
        if m>=0:
            ans.append(cnt[m^rnd].pop())
            m+=1
        else:
            print('Impossible')
            return
    print('Possible')
    print(*ans)
    return
