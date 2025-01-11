pimport sys

r=sys.stdin.readline

def _n():
    return map(int, r())
def _nA():
    return list(map(int, r().split()))
def _nS():
    return r().split()

def solve():
    x,y,z=_nA()
    x1,y1,z1=_nA()
    a1,a2,a3,a4,a5,a6=_nA()
    ret = 0
    if z < 0:
        ret += a3
    elif z > z1:
        ret += a4
    if y < 0:
        ret += a1
    elif y > y1:
        ret += a2
    if x < 0:
        ret += a5
    elif x > x1:
        ret += a6
    print(ret)

solve()
