import sys
from functools import reduce
from operator import xor

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
    n, m = mint()
    A = ints()
    B = ints()
    rs = reduce(xor, A)
    cs = reduce(xor, B)
    if rs != cs:
        print("NO")
        return
    
    print("YES")
    B[0] ^= cs ^ A[0]
    print(*B)
    ans = [0] * m
    for i in range(1, n):
        ans[0] = A[i]
        print(*ans)


solve()
