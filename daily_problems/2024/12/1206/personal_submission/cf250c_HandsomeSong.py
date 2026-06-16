import sys
input = sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,k=MII()
a=LII()
tmp=[a[0]]
for i in range(1,n):
    if a[i]!=tmp[-1]:
        tmp.append(a[i])
ans=[0]*(k+1)
for i in range(len(tmp)):
    if i==0 or i==len(tmp)-1 or tmp[i-1]!=tmp[i+1]:
        ans[tmp[i]]+=1
    else:
        ans[tmp[i]]+=2
print(ans.index(max(ans)))