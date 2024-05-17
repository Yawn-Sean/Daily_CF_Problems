s=input()
s+=s
n=len(s)
cnt=1
ans=0
for i in range(n-1):
    if s[i+1]!=s[i]:
        cnt+=1
    else:
        ans=max(ans,cnt)
        cnt=1
ans=max(ans,cnt)
print(min(ans,n//2))

