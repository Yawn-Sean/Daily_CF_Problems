def solve():
    n=int(input())
    s=input()
    s=list(s)
    ca=s.count("?")
    cl=s.count("(")
    cr=s.count(")")
    ca-=abs(cl-cr)
    if ca%2:
        return ":("
    l,r=ca//2,ca//2
    if cl>=cr:
        r+=cl-cr
    else:
        l+=cr-cl
 
    cnt=0
    for i in range(n):
        if s[i]=="(":
            cnt+=1
        elif s[i]==")":
            cnt-=1
        else:
            if l:
                s[i]="("
                cnt+=1
                l-=1
            else:
                s[i]=')'
                cnt-=1
                r-=1

        if i!=n-1:
            if cnt<=0:
                return ":("
        else:
            if cnt!=0:
                return ":("
    return ''.join(s)
print(solve())
