n, m = MII()
points = set()
for _ in range(m):
    x, y = GMI()
    if x > y:
        x, y = y, x
    
    points.add((x, y))

for i in range(1, n):
    if n % i == 0:
        tmp = i
        flg = True
        for x, y in points:
            x, y = (x + tmp) % n, (y + tmp) % n
            if x > y:
                x, y = y, x
            if (x, y) not in points:
                flg = False
                break
        if flg:
            print("Yes")
            exit()
print("No")
