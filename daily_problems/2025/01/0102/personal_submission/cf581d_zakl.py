
def _n():
    return int(input())

def _nA():
    return list(map(int, input().split()))

def _sA():
    return input().split()

def solve():
    x1,y1,x2,y2,x3,y3=_nA()
    x1,y1=sorted([x1,y1])
    x2,y2=sorted([x2,y2])
    x3,y3=sorted([x3,y3])
    ret=[]
    if max(y1,y2,y3)==min(y1,y2,y3) and y1==x1+x2+x3:
        for _ in range(x1):
            ret.append('A'*y1)
        for _ in range(x2):
            ret.append('B'*y1)
        for _ in range(x3):
            ret.append('C'*y1)
        print(y1)
        print('\n'.join(ret))
        return
    (x1,y1,v1),(x2,y2,v2),(x3,y3,v3)=sorted([(x1,y1,'A'),(x2,y2,'B'),(x3,y3,'C')], key=lambda x: -x[1])
    flag=0
    if y1==x2+x3 and y2==y3 and x1+y2==y1:
        flag=1
    elif y1==x2+y3 and y2==x3 and x1+y2==y1:
        flag=1
        x3,y3=y3,x3
    elif y1==y2+x3 and x2==y3 and x1+x2==y1:
        flag=1
        x2,y2=y2,x2
    elif y1==y2+y3 and x2==x3 and x1+x2==y1:
        flag=1
        x2,y2=y2,x2
        x3,y3=y3,x3
    if flag:
        for _ in range(x1):
            ret.append(v1*y1)
        for _ in range(y2):
            ret.append(v2*x2+v3*x3)
        print(y1)
        print('\n'.join(ret))
        return
    print(-1)    
    
    

solve()
