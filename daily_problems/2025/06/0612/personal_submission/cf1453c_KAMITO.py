def solve():
    n=II()
    a=[]
    for i in range(n):
        a.append(LMILS())
    row_left=[[n]*10 for i in range(n)]
    col_high=[[n]*10 for i in range(n)]
    row_right=[[-1]*10 for i in range(n)]
    col_low=[[-1]*10 for i in range(n)]
    high=[n]*10
    low=[-1]*10
    left=[n]*10
    right=[-1]*10
    for i in range(n):
        for j in range(n):
            row_left[i][a[i][j]]=min(row_left[i][a[i][j]],j)
            row_right[i][a[i][j]]=max(row_right[i][a[i][j]],j)
            high[a[i][j]]=min(high[a[i][j]],i)
            low[a[i][j]]=max(high[a[i][j]],i)
    for j in range(n):
        for i in range(n):
            col_high[j][a[i][j]]=min(col_high[j][a[i][j]],i)
            col_low[j][a[i][j]]=max(col_low[j][a[i][j]],i)
            left[a[i][j]]=min(left[a[i][j]],j)
            right[a[i][j]]=max(right[a[i][j]],j)
    ans=[0]*10
    for i in range(n):
        for x in range(10):
            h=max(i,n-1-i)
            d=row_right[i][x]-row_left[i][x]
            ans[x]=max(ans[x],d*h)
            for j in range(n):
                h=max(i-high[x],low[x]-i)
                d=max(j-row_left[i][x],row_right[i][x]-j)
                if h>=0 and d>=0:
                    ans[x]=max(ans[x],d*h)
    for j in range(n):
        for x in range(10):
            d=max(j,n-1-j)
            h=col_low[j][x]-col_high[j][x]
            ans[x]=max(ans[x],d*h)
            for i in range(n):
                d=max(j-left[x],right[x]-j)
                h=max(i-col_high[j][x],col_low[j][x]-i)
                if h>=0 and d>=0:
                    ans[x]=max(ans[x],d*h)
    print(*ans)
    return
