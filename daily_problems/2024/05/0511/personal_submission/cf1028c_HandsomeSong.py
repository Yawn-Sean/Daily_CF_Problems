def II():
    return int(input())
def MII():
    return map(int,input().split())
n=II()
rects=[]
for _ in range(n):
    x1,y1,x2,y2=MII()
    rects.append((x1,y1,x2,y2))
mx_x1=max(r[0] for r in rects)
mn_x2=min(r[2] for r in rects)
mx_y1=max(r[1] for r in rects)
mn_y2=min(r[3] for r in rects)
if mx_x1<=mn_x2 and mx_y1<=mn_y2:
    print(mx_x1,mx_y1)
    exit()
suspects=set()
for i, r in enumerate(rects):
    if r[0] == mx_x1:
        suspects.add(i)
        break
for i, r in enumerate(rects):
    if r[2] == mn_x2:
        suspects.add(i)
        break
for i, r in enumerate(rects):
    if r[1] == mx_y1:
        suspects.add(i)
        break
for i, r in enumerate(rects):
    if r[3] == mn_y2:
        suspects.add(i)
        break
for idx in suspects:
    c_mx_x1=-10**18
    c_mn_x2=10**18
    c_mx_y1=-10**18
    c_mn_y2=10**18
    for i,r in enumerate(rects):
        if i==idx:
            continue
        c_mx_x1=max(c_mx_x1,r[0])
        c_mn_x2=min(c_mn_x2,r[2])
        c_mx_y1=max(c_mx_y1,r[1])
        c_mn_y2=min(c_mn_y2,r[3])
    if c_mx_x1<=c_mn_x2 and c_mx_y1<=c_mn_y2:
        print(c_mx_x1,c_mx_y1)
        exit()