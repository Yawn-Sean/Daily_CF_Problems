import sys
import math

def main():
    n = int(input())
    if n%4 != 0:
        print("!", -1)
        return

    def query(x: int)->int:
        print("?", x, flush=True)
        x1 = int(input())
        print("?", x+n//2, flush=True)
        x2 = int(input())
        return x1-x2

    l, r, f1 = 1, n//2, query(1)
    if f1 == 0:
        print("!", 1)
        return
    f1 = 1 if f1 > 0 else -1
    while l < r:
        mid = (l+r) // 2
        f2 = query(mid)
        if f2 == 0:
            print("!", mid)
            return
        if f1*f2 < 0: r = mid
        else: l = mid+1
    print("!", l)
