import sys
input = sys.stdin.readline
def II():
    return int(input())
def LII():
    return list(map(int, input().split()))
n=II()
a=LII()
s=set()
for x in a:
    while x in s:
        s.remove(x)
        x+=1
    s.add(x)
m=max(s)
print(m+1-len(s))