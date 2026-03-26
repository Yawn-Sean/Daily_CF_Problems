# -*- coding: UTF-8 -*-
import math
import sys
from dataclasses import dataclass


@dataclass(slots=True)
class Vector:
    x: int
    y: int

    def __neg__(self) -> "Vector":
        return Vector(-self.x, -self.y)

    def __add__(self, other: "Vector") -> "Vector":
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other: "Vector") -> "Vector":
        return Vector(self.x - other.x, self.y - other.y)

    def __mul__(self, k) -> "Vector":
        return Vector(self.x * k, self.y * k)

    def __rmul__(self, k) -> "Vector":
        return Vector(self.x * k, self.y * k)

    def __truediv__(self, k) -> "Vector":
        return Vector(self.x / k, self.y / k)

    def dot(self, other: "Vector"):
        return self.x * other.x + self.y * other.y

    def cross(self, other: "Vector"):
        return self.x * other.y - self.y * other.x

    def norm(self):  # use math.hypot for high accuracy
        return math.sqrt(self.x**2 + self.y**2)

    def dis(self, other: "Vector"):
        return (self - other).norm()

    def norm_square(self):  # faster for sorting int
        return self.x * self.x + self.y * self.y

    def dis_square(self, other: "Vector"):  # faster for sorting int
        return (self - other).norm_square()


def sign(x: int) -> int:
    if x == 0:
        return 0
    return 1 if x > 0 else -1


input = lambda: sys.stdin.readline().rstrip()


if __name__ == "__main__":
    n = int(input())
    a = [Vector(*map(int, input().split())) for _ in range(n)]

    # adjust cordinates, make a[0] O
    for i in range(n - 1, -1, -1):
        a[i] -= a[0]

    # cnt[i][j], O,a_i,a_j triangle
    # include points STRICTLY INSIDE
    # (since no 3 points are collinear)
    # (it is ok to consider only INSIDE)
    # sign is equal to sign of cross
    cnt = [[0] * n for _ in range(n)]

    for i in range(n):
        for j in range(i + 1, n):
            cc, v1, v2 = 0, a[i], a[j]
            v12 = v2 - v1
            v2_neg = -v2
            for k, v in enumerate(a):
                if k == i or k == j:
                    continue
                if sign(v1.cross(v - v1)) == sign(v12.cross(v - v2)) == sign(v2_neg.cross(v)):
                    cc += 1
            if v1.cross(v2) > 0:
                cnt[i][j] = cc
                cnt[j][i] = -cc
            else:
                cnt[i][j] = -cc
                cnt[j][i] = cc

    ans = 0

    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                idx = [i, j, k] if (a[j] - a[i]).cross(a[k] - a[j]) > 0 else [k, j, i]
                vs = [a[x] for x in idx]
                vds = [vs[1] - vs[0], vs[2] - vs[1], vs[0] - vs[2]]
                cc = cnt[idx[0]][idx[1]] + cnt[idx[1]][idx[2]] + cnt[idx[2]][idx[0]]

                """
                print(f"{cc=}")
                print(f"\t{idx[0]} {a[idx[0]]}")
                print(f"\t{idx[1]} {a[idx[1]]}")
                print(f"\t{idx[2]} {a[idx[2]]}")
                print(f"\t{cnt[idx[0]][idx[1]]} {cnt[idx[1]][idx[2]]} {cnt[idx[2]][idx[0]]}")
                """

                if sign(vds[0].cross(-vs[1])) == sign(vds[1].cross(-vs[2])) == sign(vds[2].cross(-vs[0])):
                    cc += 1
                else:
                    x, y = 1, 2
                    vx, vy = vs[1], vs[2]
                    for p in range(3):
                        v = vs[p]
                        if sign(vx.cross(v - vx)) == sign(vds[x].cross(v - vy)) == sign((-vy).cross(v)):
                            cc -= 1
                            break  # at most 1 point should be extracted
                        x, vx = y, vy
                        y += 1
                        if y == 3:
                            y = 0
                        vy = vs[y]

                ans += cc * (cc - 1) * (cc - 2) // 6

    print(ans)
