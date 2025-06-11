import sys
input = lambda: sys.stdin.readline().strip()
from itertools import count

def solve():
    def calc(tgt: int) -> int:
        res = 0
        for i in count(2):
            if (x := i**3) > tgt:
                break
            # l = r = 1
            # while x * r < tgt: 
            #     r <<= 1
            # while l < r:
            #     mid = (l + r + 1) >> 1
            #     if x * mid > tgt:
            #         r = mid - 1
            #     else:
            #         l = mid
            # res += l
            res += tgt // x
        return res
    
    l = r = 1
    while calc(r) < m: 
        r <<= 1
    while l < r:
        mid = (l + r) >> 1
        if calc(mid) < m:
            l = mid + 1
        else:
            r = mid
    print(l if calc(l) == m else -1)
    
      
for _ in range(1):
    m = int(input())
    solve()