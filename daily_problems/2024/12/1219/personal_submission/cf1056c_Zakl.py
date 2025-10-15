
from sys import stdout

def _n():
    return int(input())
def _nA():
    return list(map(int, input().split()))
def _sA():
    return input().split()
used=set()
n,m=_nA()
ps=_nA()
pw={}
for i,v in enumerate(ps):
    pw[i+1]=v
ps=sorted(list(range(1,len(ps)+1)),key=lambda x: -pw[x])
hd={}
hs=[]
for _ in range(m):
    pr=_nA()
    ps.append(pr)
    hd[pr[0]]=pr[1]
    hd[pr[1]]=pr[0]
    if pw[pr[0]]>pw[pr[1]]: hs.append(pr[0])
    else: hs.append(pr[1])
turn=_n()
hs.sort(key= lambda x:-pw[x])
def getSb(): return _n()
def pt(x):
    print(x)
    used.add(x)
    stdout.flush()
idx=0
hidx=0
flag=(turn==1)
while idx<2*n:
    while idx<2*n and ps[idx] in used:
        idx+=1
    if idx>=2*n: break
    if flag:
        while hidx<m and hs[hidx] in used:
            hidx+=1
        if hidx<m:
            pt(hs[hidx])
            flag=0
            continue
        if idx<2*n:
            pt(ps[idx])
            flag=0
        else: break
    else:
        x=getSb()
        used.add(x)
        if x in hd:
            if hd[x] not in used:
                pt(hd[x])
                continue
        flag=1
            
