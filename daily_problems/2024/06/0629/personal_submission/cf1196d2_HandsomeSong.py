def II():
    return int(input())
def MII():
    return map(int, input().split())
def LI():
    return list(input().strip())
    
q=II()
pattern = "RGB"
for _ in range(q):
    n,k=MII()
    s=LI()
    ans=k-1
    for a in range(3):
        window=0
        for j in range(n):
            if s[j]==pattern[(j+a)%3]:
                window+=1
            if j>=k:
                if s[j-k]==pattern[(j-k+a)%3]:
                    window-=1
            if j>=k-1:
                ans=min(ans,k-window)
    print(ans)