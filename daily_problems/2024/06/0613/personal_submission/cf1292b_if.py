x0,y0,ax,ay,bx,by=map(int,input().split())
x,y,t=map(int,input().split())
pts=[(x0,y0)]
while len(pts)<100:
	pts.append((pts[-1][0]*ax+bx,pts[-1][1]*ay+by))
best=0
for i in range(100):
	for j in range(i,100):
		agg=0
		for k in range(i,j):
			agg+=abs(pts[k][0]-pts[k+1][0])+abs(pts[k][1]-pts[k+1][1])
		if agg+abs(pts[i][0]-x)+abs(pts[i][1]-y)<=t:best=max(best,j-i+1)
		if agg+abs(pts[j][0]-x)+abs(pts[j][1]-y)<=t:best=max(best,j-i+1)
print(best)
