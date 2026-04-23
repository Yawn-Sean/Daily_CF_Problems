import sys
input = sys.stdin.readline
def II():
    return int(input())
def I():
    return input().strip()
n=II()
s=I()
cnt_g=s.count('G')
ans=0
l,r=0,0
cnt=0
while l<n:
    while r<n and cnt+(s[r]=='S')<=1:
        cnt+=(s[r]=='S')
        r+=1
    ans=max(ans,r-l)
    if s[l]=='S':
        cnt-=1
    l+=1
print(min(ans,cnt_g))