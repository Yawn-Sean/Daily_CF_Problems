n = int(input())
points = [(i,i) for i in range(1,n+3)]
for i in range(1,n+2):
    points.append((i,i+1))
    points.append((i+1,i))

print(len(points))
for (i,j) in points:
    print(i,j)
