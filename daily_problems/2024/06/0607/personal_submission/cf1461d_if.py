def check(a):
    global k
    if tuple(a) in k:
        return
    k.add(tuple(a))
    p=sum(a)
    ans.add(p)
    if len(a)<=1:
        return 
    l=min(a)
    r=max(a)
    a1=[i for i in a if i<=(l+r)//2]
    a2=[i for i in a if i>(l+r)//2]
    check(a1)
    check(a2)
for _ in range(int(input())):
    k=set()
    n,q=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    s=[]
    ans=set()
    for i in range(q):
        s.append(int(input()))
    check(a)
    for i in s:
        if i in ans:
            print("yes")
        else:
            print("no")
        

