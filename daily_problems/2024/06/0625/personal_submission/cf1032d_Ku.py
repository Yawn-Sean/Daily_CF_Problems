a,b,c = RII()
x1,y1,x2,y2 = RII()
def dist(x,y):
    return ((x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2) ** 0.5
def find(x,y):
    #ax+by+c = 0
    li = []
    if b != 0: li.append((x,(-c-a*x)/b))
    if a != 0: li.append(((-c-b*y)/a,y))
    return li
ans = abs(x1-x2) + abs(y1-y2)
li1 = find(x1,y1)
li2 = find(x2,y2)
for j1,j2 in li1:
    for j3,j4 in li2:
        ans = min(ans,dist((x1,y1),(j1,j2)) +dist((j1,j2),(j3,j4)) + dist((j3,j4),(x2,y2)))
print(ans)
