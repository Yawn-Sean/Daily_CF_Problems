import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
y=LII()
for i in range(3):
    for j in range(i):
        k=(y[i]-y[j])*2//(i-j)
        vis=set()
        for x in range(n):
            vis.add(y[x]*2-x*k)
            if len(vis)>2:
                break
        if len(vis)==2:
            print('Yes')
            exit()
print('No')