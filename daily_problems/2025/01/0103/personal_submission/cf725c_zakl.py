def solve():
    s=input()
    for x,y in pairwise(s):
        if x==y:
            print("Impossible")
            return
    l=r=0
    for x in s:
        if s.find(x)!=s.rfind(x):
            l=s.find(x)
            r=s.rfind(x) 
    mid=(r-1-(l+1)+1)//2
    line1=s[:l+mid+1]
    # 删掉 s[l]
    x=s[l]
    line2=s[l+mid+1:]
    ix=line2.find(x)
    line2=line2[:ix]+line2[ix+1:]

    if len(line1)>13:
        t=line1[:len(line1)-13]
        line1=line1[len(line1)-13:]
        line2+=t
    elif len(line2)>13:
        t=line2[13:]
        line2=line2[:13]
        line1=t+line1
    print(line1)
    print(line2[::-1])

solve()
