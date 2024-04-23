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
    n = sint()
    arr = ints()
    
    dp = [0] * 5

    for x in arr:
        if x == 1:
            dp[1] += 1
            dp[2] = max(dp[1], dp[2])
            dp[3] = max(dp[2], dp[3]+1)
            dp[4] = max(dp[3], dp[4])
        else:
            dp[2] = max(dp[1], dp[2]+1)
            dp[3] = max(dp[2], dp[3])
            dp[4] = max(dp[3], dp[4]+1)

    print(dp[4])

for _ in range(int(input())):
    solve()
