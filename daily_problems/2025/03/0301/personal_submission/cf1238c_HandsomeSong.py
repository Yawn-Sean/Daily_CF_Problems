import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
q=II()
for _ in range(q):
    h,n=MII()
    p=LII()
    p.append(0)
    ans=0
    i=0
    while i<n  and p[i]>0:
        if p[i]-p[i+1]>1:
            p[i]=p[i+1]+1
        else:
            if p[i+1]==0:
                break
            if p[i+2]==p[i]-2:
                i+=2
            else:
                ans+=1
                p[i+1]=p[i]-2
                i+=1
    print(ans)