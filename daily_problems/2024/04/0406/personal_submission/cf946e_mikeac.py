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
    s = list(map(int, list(input())))
    mask = 0
    for c in s:
        mask ^= 1 << c
    
    # if mask == 0:
    #     print(*s, sep='')
    #     return
    
    n = len(s)
    for i in range(n - 1, -1, -1):
        mask ^= 1 << s[i]
        for d in range(s[i] - 1, -int(i > 0), -1):
            nmask = mask ^ (1 << d)
            cnt = bin(nmask)[2:].count('1')
            if cnt <= n - i - 1:
                ans = s[:i] + [d] + [9] * (n - i - 1 - cnt) + [v for v in range(9, -1, -1) if (nmask >> v) & 1]
                print(*ans, sep='')
                return

    ans = [9] * (n - 2)
    print(*ans, sep='')

for _ in range(int(input())):
    solve()
