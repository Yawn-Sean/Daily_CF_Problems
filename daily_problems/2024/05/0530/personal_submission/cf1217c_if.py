def check(i):
    for j in range(i,n):
        if s[j]=='1':
            break
    ans=0
    m=''
    for  k in range(j,n):
        m+=s[k]
        if k-i+1<int(m,2):
            break
        else:
            ans+=1
    return ans
for _ in range(int(input())):
    s=input()
    n=len(s)
    ans=0
    ans+=check(0)
    for i in range(1,n):
        if (s[i]=="1" and s[i-1]!='0') or (s[i]=="0" and s[i]!=s[i-1]):
            ans+=check(i)
    if s[-1]=="0":
        ans-=1
    print(ans)
