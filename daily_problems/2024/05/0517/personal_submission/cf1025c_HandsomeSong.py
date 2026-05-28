import sys
input = sys.stdin.readline
def I():
    return input().strip()
s=I()
n=len(s)
mx=1
cur=1
for i in range(1,2*n):
    if s[i%n]!=s[(i-1)%n]:
        cur+=1
    else:
        cur=1
    mx=max(mx,cur)
print(min(mx,n))