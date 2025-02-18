def main():
    n = int(input())
    xs = [0] * (n + 1)
    ys = [0] * (n + 1)
    zs = [0] * (n + 1)
    for i in range(n + 1):
        xs[i], ys[i], zs[i] = map(int, input().split())
    vp,vs = map(int, input().split())
    px, py, pz = map(int, input().split())

    def distince(x1, y1, z1, x2, y2, z2):
        return ((x1 - x2) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2) ** 0.5
    cur = 0
    for i in range(n):
        new_time = distince(xs[i], ys[i], zs[i], xs[i+1], ys[i+1],zs[i+1] ) / vs
        t = distince(xs[i+1], ys[i+1],zs[i+1], px, py, pz) / vp
        if t <= new_time + cur:
            l, r = 0, 1 # 二分
            for _ in range(50):
                m = (l + r) / 2
                nx, ny, nz = xs[i] + m * (xs[i + 1] - xs[i]), ys[i] + m * (ys[i + 1] - ys[i]), zs[i] + m * (zs[i + 1] - zs[i])
                if distince(px, py, pz, nx, ny, nz) / vp <= cur + distince(xs[i], ys[i], zs[i], nx, ny, nz) / vs:
                    r = m
                else:
                    l = m
            nx, ny, nz = xs[i] + m * (xs[i + 1] - xs[i]), ys[i] + m * (ys[i + 1] - ys[i]), zs[i] + m * (zs[i + 1] - zs[i])
            print('YES')
            print(distince(px, py, pz, nx, ny, nz) / vp)
            print(nx, ny, nz)
            return
        cur += new_time
    print('NO')
main()