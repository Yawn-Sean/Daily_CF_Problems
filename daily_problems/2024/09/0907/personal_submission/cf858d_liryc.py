'''
https://codeforces.com/contest/858/submission/280173937
858 D
2024/9/7 Y1
1600
Counter (使用set优化)
上一版使用Counter+chain出现了爆内存，需注意：https://codeforces.com/contest/858/submission/280171437
'''

from itertools import chain, combinations
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = []
    for _ in range(n):
        a.append(input())
    return n, a

def solve(n: int, a: list[str]):
    s1, s2 = set(), set()
    for s in a:
        hs = set()
        for i, j in combinations(range(10), 2):
            t = s[i:j]
            if t in s2:
                pass
            elif t in s1:
                s2.add(t)
                s1.remove(t)
            else:
                hs.add(t)
        s1 |= hs
    def ss(s):
        nonlocal s1
        for le in range(1, 10):
            for j in range(le, 10):
                t = s[j - le:j]
                if t in s1:
                    return t        
    return [ss(s) for s in a]

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(*ans, sep='\n')
