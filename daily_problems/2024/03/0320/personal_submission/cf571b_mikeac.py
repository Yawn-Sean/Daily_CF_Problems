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
    n, k =  mint()
    nums = ints()
    nums.sort()
    
    a, b = divmod(n, k)
    
    dp = [math.inf] * (b + 1)
    dp[0] = 0
    for i in range(k):
        for j in range(b, -1, -1):
            if j < b:
                dp[j+1] = min(dp[j+1], dp[j] + nums[(i + 1) * a + j] - nums[i * a + j])
            dp[j] += nums[(i + 1) * a + j - 1] - nums[i * a + j]
    
    print(dp[b])


solve()
