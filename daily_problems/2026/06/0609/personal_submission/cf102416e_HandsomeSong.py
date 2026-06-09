import sys
input = sys.stdin.readline
def II():
    return int(input())
def MII():
    return map(int, input().split())
n=II()
sphere=[]
for i in range(n):
    x,y,z,r=MII()
    sphere.append((r,x,y,z,i+1))
sphere.sort(key=lambda s:-s[0])
chosen=[]
for i in range(n):
    ri,xi,yi,zi,idxi=sphere[i]
    cov=False
    for j in chosen:
        rj,xj,yj,zj,idxj=j
        if (3*rj-ri)**2>=(xi-xj)**2+(yi-yj)**2+(zi-zj)**2 and 3*rj-ri>=0:
            cov=True
            break
    if not cov:
        chosen.append(sphere[i])
print(len(chosen))
print(' '.join(str(s[4]) for s in chosen))