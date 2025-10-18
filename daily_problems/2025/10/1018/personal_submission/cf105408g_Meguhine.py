# -*- coding: UTF-8 -*-
from Yawn_Sean_Template import *

N = int(math.sqrt(10**7+1))
# sieve primes in [2,N-1]
pri = []
not_prime = [False] * N
def sieve():
    for i in range(2, N):
        if not not_prime[i]:
            pri.append(i)
        for pri_j in pri:
            if i * pri_j >= N:
                break
            not_prime[i * pri_j] = True
            if i % pri_j == 0:
                break

def main():
    n=II()
    a=LII()
    g=a[0]
    for i in range(1,n):
        g=math.gcd(g,a[i])
    vis=set()
    def check(x) -> None:
        for _,p in enumerate(pri):
            if x%p==0:
                if p in vis:
                    print("NO")
                    exit(0)
                vis.add(p)
        return
    for i in range(n):
        check(a[i]//g)
    print("YES")
    return

multi_test = 0
if __name__ == "__main__":
    sieve()
    dbg(f"sieve {N} ok, len = {len(pri)}")
    T = II() if multi_test else 1
    for _ in range(T):
        main()
