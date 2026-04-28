import sys
input = sys.stdin.readline
def II():
    return int(input())
n=II()
ans=1
for i in range(1,n+1):
    ans*=min(i,n-i+1)
print(ans)