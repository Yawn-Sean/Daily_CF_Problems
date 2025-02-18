import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())

prods = [(1 << i) + 1 for i in range(31)]

def solve():
    n, mod = mii()
    n += 1
    k = n.bit_length() - 1
    ans = (n - (1 << k) + 1) % mod
    for i in range(k):
        ans = (ans * prods[i]) % mod
    return (ans - 1) % mod

for _ in range(ii()):
    print(solve())