import sys
input=sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int,input().split()))
n=II()
nums=LII()
parent=[-1]
for x in LII():
    parent.append(x-1)
ans=0
dp1=[0]*n
dp2=[0]*n
for i in range(n-1,-1,-1):
    ans=max(ans,dp1[i]+dp2[i])
    ans=max(ans,nums[i]+dp1[i])
    if i:
        v=max(nums[i],dp1[i])+1
        p=parent[i]
        if v>dp1[p]:
            dp1[p],dp2[p]=v,dp1[p]
        elif v>dp2[p]:
            dp2[p]=v
print(ans)