# Submission link: https://codeforces.com/contest/65/submission/299415339
def main():
    n = II()
    xs = [0] * (n + 1)
    ys = [0] * (n + 1)
    zs = [0] * (n + 1)

    for i in range(n + 1):
        xs[i], ys[i], zs[i] = MII()

    vp, vs = MII()
    px, py, pz = MII()

    def dis(x1, y1, z1, x2, y2, z2):
        return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)) ** 0.5

    cur_time = 0
    for i in range(n):
        new_time = dis(xs[i], ys[i], zs[i], xs[i + 1], ys[i + 1], zs[i + 1]) / vs
        time = dis(px, py, pz, xs[i + 1], ys[i + 1], zs[i + 1]) / vp
        if time <= cur_time + new_time:
            l, r = 0, 1
            for _ in range(50):
                m = (l + r) / 2
                nx, ny, nz = xs[i] + m * (xs[i + 1] - xs[i]), ys[i] + m * (ys[i + 1] - ys[i]), zs[i] + m * (zs[i + 1] - zs[i])
                if dis(px, py, pz, nx, ny, nz) / vp <= cur_time + dis(xs[i], ys[i], zs[i], nx, ny, nz) / vs:
                    r = m
                else:
                    l = m
            nx, ny, nz = xs[i] + m * (xs[i + 1] - xs[i]), ys[i] + m * (ys[i + 1] - ys[i]), zs[i] + m * (zs[i + 1] - zs[i])
            print('YES')
            print(dis(px, py, pz, nx, ny, nz) / vp)
            print(nx, ny, nz)
            exit()
        cur_time += new_time

    print('NO')