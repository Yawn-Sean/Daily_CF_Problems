import math
import sys

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
    r, b, k = mint()
    if r == b:
        print("OBEY")
        return
    
    if r < b:
        r, b = b, r

    g = math.gcd(r, b)
    
    
    print("OBEY" if g + (k - 1) * b >= r else "REBEL")

for _ in range(int(input())):
    solve()
