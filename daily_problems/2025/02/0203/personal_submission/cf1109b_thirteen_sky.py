def main():
    s=input()
    n=len(s)
    f=False
    for i in range(n//2):
        if s[i]!=s[0]: f=True;break
    if not f: return "Impossible"
    for i in range(n//2):
        if s[i+1:]+s[:i+1]==s:continue
        f=True
        for j in range(i+1):
            if s[j]!=s[2*i+1-j]:f=False;break
        for j in range(2*i+2,n):
            if s[j]!=s[2*i+2+n-1-j]:f=False;break
        if f:return 1
    return 2


print(main())
