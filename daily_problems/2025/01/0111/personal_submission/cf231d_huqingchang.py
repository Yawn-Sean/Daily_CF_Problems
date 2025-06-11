def main():
    x, y, z = MII()
    x1, y1, z1 = MII()
    a = [0] + LII()
    ans = 0
    if z > z1:
        ans += a[4]
    if z < 0:
        ans += a[3]
    if x > x1:
        ans += a[6]
    if x < 0:
        ans += a[5]
    if y > y1:
        ans += a[2]
    if y < 0:
        ans += a[1]
    return ans


T = 1
for ii in range(T):
    print(main())
