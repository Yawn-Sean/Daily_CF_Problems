import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

from collections import defaultdict

n = ii()
coordx = defaultdict(lambda: defaultdict(list))
for idx in range(1, n+1):
    x, y, z = mii()
    coordx[x][y].append((z, idx))

prex = -1
for x in sorted(coordx.keys()):
    coordy = coordx[x]
    prey = -1
    for y in sorted(coordy.keys()):
        coordz = coordy[y]
        coordz.sort()
        for i in range(1, len(coordz), 2):
            print(coordz[i-1][1], coordz[i][1])
        if len(coordz) % 2 == 1:
            if prey == -1:
                prey = coordz[-1][1]
            else:
                print(prey, coordz[-1][1])
                prey = -1
    if prey != -1:
        if prex == -1:
            prex = prey
        else:
            print(prex, prey)
            prex = -1