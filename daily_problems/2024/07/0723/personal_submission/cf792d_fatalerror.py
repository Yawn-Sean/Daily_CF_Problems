import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())

n, nq = mii()
height = n.bit_length() - 1

def solve():
    x = ii()
    h = (x & -x).bit_length() - 1
    for ch in input():
        if ch == 'U':
            if h < height:
                if x >> (h+1) & 1:
                    x -= 1 << h
                else:
                    x += 1 << h
                h += 1
        else:
            if h > 0:
                h -= 1
                if ch == 'L':
                    x -= 1 << h
                else:
                    x += 1 << h
    return x

for _ in range(nq):
    print(solve())