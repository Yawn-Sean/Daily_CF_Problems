
def read_ints():
    return [int(x) for x in input().split(' ')]

def slv():
    n,=read_ints()
    a=read_ints()
    dig1=[]
    dig2=[]
    res=[]
    for i in range(n):
        v=a[i]
        if v==1:
            dig1.append(i+1)
        else:
            dig2.append([i+1,v])
            if len(dig2)>1:
                res.append((dig2[-1][0],dig2[-2][0]))
                dig2[-1][1]-=1
                dig2[-2][1]-=1
    
    diam = len(dig2) - 1 + min(2, len(dig1))
    j=0
    for i in range(len(dig1)):
        if i==1:
            if dig2[-1][1]==0:
                print('NO')
                return
            dig2[-1][1]-=1
            res.append((dig1[i],dig2[-1][0]))
        else:
            while j<len(dig2) and dig2[j][1]==0:
                j+=1
            if j>=len(dig2):
                print('NO')
                return
            dig2[j][1]-=1
            res.append((dig1[i],dig2[j][0]))
    print('YES', diam)
    print(len(res))
    for r in res:
        print(*r)

T = 1
for _ in range(T):
    slv()
