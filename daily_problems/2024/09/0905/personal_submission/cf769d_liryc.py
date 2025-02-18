'''
https://codeforces.com/contest/769/submission/279938365
769 D
2024/9/5 Y1
1700
Counter
'''

from collections import Counter
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    return n, k, a

def solve(n: int, k: int, a: list[int]):
    cn = Counter(a)

    if k == 0:
        return sum(c * (c - 1) >> 1 for c in cn.values())
    else:
        b = [i for i in range(16384) if i.bit_count() == k]
        ans = 0
        for i in range(16384):
            for v in b:
                if i in cn and (i ^ v) in cn:
                    ans += cn[i] * cn[i ^ v]
        return ans >> 1
    
if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
