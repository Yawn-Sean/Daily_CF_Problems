def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
a.sort()
sm=0
for x in a:
    sm+=max(x,0)
sm+=min(a[n//2],0)
print(sm)