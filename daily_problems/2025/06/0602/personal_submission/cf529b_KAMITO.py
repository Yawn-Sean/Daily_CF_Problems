def solve():
    n=II()
    w=[0]*n;h=[0]*n
    for i in range(n):
        w[i],h[i]=MII()
    ans=inf
    def process(i,H,W,c):
        Ws=[]
        m=0
        res=inf
        for j in range(n):
            if j==i:
                continue
            if h[j]>H:
                if w[j]>H:
                    break
                else:
                    c+=1
                    W+=h[j]
                    if c>n//2:
                        break
            elif w[j]>H:
                W+=w[j]
            else:
                Ws.append([w[j],h[j]])
                m+=1
        else:
            Ws.sort(key=lambda x:x[1]-x[0])
            for j in range(m):
                w_j,h_j=Ws[j]
                if w_j>h_j:
                    if c<n//2:
                        W+=h_j
                        c+=1
                    else:
                        W+=w_j
                else:
                    W+=w_j
            res=W*H
        return res
    for i in range(n):
        ans=min(ans,process(i,h[i],w[i],0))
        ans=min(ans,process(i,w[i],h[i],1))
    print(ans)
    return
