def solve():
    s=I()
    n=II()
    b=[]
    for i in range(n):
        b.append(I())
    
    m=len(s)
    def check(j,i):
        for k in range(n):
            l=len(b[k])
            if i-l+1>=j and s[i-l+1:i+1]==b[k]:
                return False
        return True
    ans=l=-1
    j=0
    for i in range(m):
        while j<=i and not check(j,i):
            j+=1
        if i-j+1>ans:
            ans=i-j+1
            l=j
    print(ans,l)
    return
