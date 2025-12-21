"""
https://codeforces.com/gym/105292/submission/354437569
"""

import sys

input = sys.stdin.buffer.readline
n, m = map(int, input().split())
grid = [bytearray(input().rstrip(b"\n")) for _ in range(n)]

DOT = ord(".")
WALL = ord("#")
BULB = ord("L")
LIT = ord("1")

for i in range(n):
    row = grid[i]
    for j in range(m):
        if row[j] == DOT:
            row[j] = BULB
            # for k in range(i - 1, -1, -1):
            #     if grid[k][j] == WALL:
            #         break
            #     grid[k][j] = LIT
            for k in range(i + 1, n):
                if grid[k][j] == WALL:
                    break
                grid[k][j] = LIT
            # for k in range(j - 1, -1, -1):
            #     if row[k] == WALL:
            #         break
            #     row[k] = LIT
            for k in range(j + 1, m):
                if row[k] == WALL:
                    break
                row[k] = LIT

trans = bytes.maketrans(b"1", b".")
out = sys.stdout.buffer.write
for row in grid:
    out(row.translate(trans))
    out(b"\n")
