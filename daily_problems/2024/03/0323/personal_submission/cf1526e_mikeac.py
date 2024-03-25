import math
import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    n, k = mint()
    suff = ints()
    pos = [-1] * (n + 1)
    for i, x in enumerate(suff):
        pos[x] = i
    
    cnt = 0
    for i in range(1, n):
        if pos[suff[i - 1] + 1] < pos[suff[i] + 1]:
            cnt += 1
    if k + cnt < n:
        print(0)
        return
    mx = k + cnt
    # 阶乘
    fact = [1] * (mx + 1)
    for i in range(1, mx + 1):
        fact[i] = fact[i-1] * i % MOD
    
    ans = fact[k + cnt] * pow(fact[n], MOD - 2, MOD) * pow(fact[k + cnt - n], MOD - 2, MOD) % MOD
    print(ans)

solve()
