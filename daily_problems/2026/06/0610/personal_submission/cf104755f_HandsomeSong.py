import sys
input=sys.stdin.readline
def LII():
    return list(map(int, input().split()))
def MII():
    return map(int, input().split())
n,m=MII()
a=LII()
b=LII()
tar=set(b)
valid=[]
points=set()
used=set()
for bj in b:
    c=2*a[0]-bj
    if c in used:
        continue
    is_valid=True
    current_illuminated=[]
    for ai in a:
        illuminated_point=2*ai-c
        if illuminated_point not in tar:
            is_valid=False
            break
        current_illuminated.append(illuminated_point)
    if is_valid:
        valid.append(c)
        used.add(c)
        for p in current_illuminated:
            points.add(p)
if len(points) == len(tar):
    print("Yes")
    print(len(valid))
    print(*(valid))
else:
    print("No")