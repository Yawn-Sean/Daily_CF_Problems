s=input()
n=len(s)
ans=0
for i in range(n):
    cnt=0
    r=0
    for j in range(i,n):
        if s[j]=="(":
            cnt+=1
        if s[j]==")":
            cnt-=1
        if s[j]=="?":
            cnt-=1
            r+=1
        if cnt<0:
            if r==0:
                break
            r-=1
            cnt+=2
        if cnt==0:
            ans+=1
print(ans)
    
