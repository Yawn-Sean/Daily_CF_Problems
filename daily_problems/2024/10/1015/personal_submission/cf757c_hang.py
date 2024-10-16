import random
from collections import Counter
def main():
    n,m = map(int,input().split())
    g = []
    for i in range(n): g.append(list(map(int,input().split())))
    pw = random.randint(10 ** 5 + 5, 2 * 10 ** 5 + 5)
    md = random.getrandbits(46)
    p = [0] * (m)

    for i,tmp in enumerate(g):
        for v in tmp[1:]:
            v -= 1
            p[v] = p[v] * pw % md + i + 1
            if p[v] >= md: p[v] -= md

    mod = 10 ** 9 + 7
    res = 1
    for v in Counter(p).values():
        for i in range(1, v + 1):
            res = res * i % mod
    print(res)
        
main()