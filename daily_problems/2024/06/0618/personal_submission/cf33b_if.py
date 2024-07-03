inf=float("inf")
def slove():
    s1=input()
    s2=input()

    if len(s1)!=len(s2):
        print(-1)
        return
    path=[[inf]*26 for _ in range(26)]
    for _ in range(int(input())):
        a,b,w=input().split()
        a=ord(a)-ord('a')
        b=ord(b)-ord('a')

        w=int(w)
        path[a][b]=min(path[a][b],w)

    for i in range(26):
        path[i][i]=0
    for k in range(26):
        for i in range(26):
            for j in range(26):
                path[i][j] = min(path[i][j], path[i][k] + path[k][j])

    ans=0
    ss=[]
    for i,j in zip(s1,s2):
        if i==j:ss.append(i)
        else:
            i,j=ord(i)-ord('a'),ord(j)-ord('a')
            c=''
            d=inf
            for k in range(26):
                aa=path[i][k]
                bb=path[j][k]
                if aa==inf or bb==inf :continue
                elif aa+bb<d:
                    d=aa+bb
                    c=chr(ord('a')+k)
            if d==inf:
                print(-1)
                return
            ans+=d
            ss.append(c)
    print(ans)
    print(''.join(ss))
slove()
