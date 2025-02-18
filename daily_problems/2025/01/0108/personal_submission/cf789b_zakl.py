def _n():
    return int(input())
def _nA():
    return list(map(int, input().split()))
def _nS():
    return input().split()
def solve():
    b,q,l,m=_nA()
    a=set(_nA())
    vis=set()
    ret=0
    c=0
    vis2=set()
    if q==-1:
        if b in a and b*-1 in a:
            print(0)
            return
        elif b in a or b*-1 in a:
            if b<=l:
                print('inf')
            else:
                print(0)
            return
    while 1:
        x=b*(q**c)
        c+=1
        if abs(x)>l:
            break
        if x in a:
            if x in vis2:
                break
            vis2.add(x)
            continue
        if x not in vis:
            ret+=1
            vis.add(x)
        else:
            print('inf')
            return
    print(ret)
solve()
