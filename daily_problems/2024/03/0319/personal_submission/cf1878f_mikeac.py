import sys
from collections import Counter

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    n, q = mint()
    
    def getPrimes(n: int, res: Counter):
        d = 2
        while d * d <= n:
            if n % d == 0:
                while n % d == 0:
                    res[d] += 1
                    n //= d
            if n == 1:
                break
            d += 1
        if n > 1:
            res[n] += 1
        return res
            
    cnt = Counter()
    x = n
    getPrimes(x, cnt)
    
    x = n
    cc = cnt.copy()
    for _ in range(q):
        qry = ints()
        if qry[0] == 2:
            x = n
            cc = cnt.copy()
        else:
            x *= qry[1]
            getPrimes(qry[1], cc)
            p = 1
            for v in cc.values():
                p *= (v + 1)
            print("YES" if x % p == 0 else "NO")
    print()

for _ in range(int(input())):
    solve()