def solve():
    s=input().split(',')
    comment=[]
    n=len(s)
    for i in range(0,n,2):
        c,k=s[i:i+2]
        comment.append([c,int(k)])
    n=len(comment)
    ans=[]
    q=[]
    idx=-1
    def dfs(i,d):
        nonlocal idx
        c,k=comment[i]
        if len(ans)==d:
            ans.append([c])
        else:
            ans[d].append(c)
        for _ in range(k):
            idx+=1
            dfs(idx,d+1)
        return
    while idx<n-1:
        idx+=1
        dfs(idx,0)
    print(len(ans))
    for i in ans:
        print(*i)
    return
