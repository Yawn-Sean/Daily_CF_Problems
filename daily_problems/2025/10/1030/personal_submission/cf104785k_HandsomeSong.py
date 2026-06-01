import sys
input = sys.stdin.readline
def MII():
    return map(int, input().split())
n,m=MII()
forward=[]
backward=[]
for i in range(m):
    a,b=MII()
    if a<b:
        forward.append(i+1)
    else:
        backward.append(i+1)
print('YES')
if len(forward)>=len(backward):
    print(len(forward))
    print(" ".join(map(str,forward)))
else:
    print(len(backward))
    print(" ".join(map(str,backward)))