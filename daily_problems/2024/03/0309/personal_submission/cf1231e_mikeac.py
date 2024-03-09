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
    n = sint()
    s = input()
    t = input()
    if Counter(s) != Counter(t):
        print(-1)
        return
    ans = n - 1
    for i in range(n):
        j, k = i, 0
        while j < n and k < n:
            if s[k] == t[j]:
                j += 1
            k += 1
        ans = min(ans, n - j + i)
    print(ans)

for _ in range(int(input())):
    solve()
