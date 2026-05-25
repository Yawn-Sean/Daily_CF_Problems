import sys
input = sys.stdin.readline
def II():
    return int(input())
def I():
    return input().strip()
n=II()
s=I()
left=[1]*n
right=[1]*n
for i in range(1,n):
    if s[i]==s[i-1]:
        left[i]=left[i-1]+1
for i in range(n-2,-1,-1):
    if s[i+1]==s[i]:
        right[i]=right[i+1]+1
beauty=0
i=0
while i<n:
    length=right[i]
    beauty+=length**2
    i+=length
mx=-10**18
for i in range(n-1):
    if s[i]!=s[i+1]:
        lx=left[i]
        ry=right[i+1]
        ly=0
        if i>0 and s[i-1]==s[i+1]:
            ly=left[i-1]
        rx=0
        if i+2<n and s[i+2]==s[i]:
            rx=right[i+2]
        mx=max(mx,2*(ly+rx-lx-ry+2))
print(beauty+mx)