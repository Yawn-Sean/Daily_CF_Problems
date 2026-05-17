import sys
input = sys.stdin.readline
def II():
    return int(input())
def I():
    return input().strip()
n=II()
s=I()
c=0
for i in range(n-1):
    if s[i]==s[i+1]:
        c+=1
ans=min(n,n-c+2)
print(ans)