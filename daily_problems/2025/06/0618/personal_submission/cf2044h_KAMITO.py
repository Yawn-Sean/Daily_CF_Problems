def solve():
    n,q=MIIS()
    M=[]
    for i in range(n):
        M.append(LIIS())

    pre_M=[[M[i][j] for j in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            if i-1>=0:
                pre_M[i][j]+=pre_M[i-1][j]
            if j-1>=0:
                pre_M[i][j]+=pre_M[i][j-1]
            if i-1>=0 and j-1>=0:
                pre_M[i][j]-=pre_M[i-1][j-1]

    pre_M_ij=[[M[i][j]*(n*i+j+1) for j in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            if i-1>=0:
                pre_M_ij[i][j]+=pre_M_ij[i-1][j]
            if j-1>=0:
                pre_M_ij[i][j]+=pre_M_ij[i][j-1]
            if i-1>=0 and j-1>=0:
                pre_M_ij[i][j]-=pre_M_ij[i-1][j-1]

    pre_M_i=[[M[i][j]*i for j in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            if i-1>=0:
                pre_M_i[i][j]+=pre_M_i[i-1][j]
            if j-1>=0:
                pre_M_i[i][j]+=pre_M_i[i][j-1]
            if i-1>=0 and j-1>=0:
                pre_M_i[i][j]-=pre_M_i[i-1][j-1]

    def get_S(a,x1,y1,x2,y2):
        return a[x2][y2]-(a[x1-1][y2] if x1>=1 else 0)-(a[x2][y1-1] if y1>=1 else 0)+(a[x1-1][y1-1] if x1>=1 and y1>=1 else 0)

    for i in range(q):
        x1,y1,x2,y2=MIIS()
        x1-=1;y1-=1
        x2-=1;y2-=1
        h=x2-x1+1
        w=y2-y1+1
        ans=get_S(pre_M_ij,x1,y1,x2,y2)
        res=(n-w)*get_S(pre_M_i,x1,y1,x2,y2)+(w*x1+y1)*get_S(pre_M,x1,y1,x2,y2)
        ans-=res
        print(ans,end=' \n'[i==q-1])
    return

test=1
test=int(input())
for _ in range(test):
    solve()
