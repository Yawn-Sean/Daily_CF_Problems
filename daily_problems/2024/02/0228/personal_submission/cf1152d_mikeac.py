import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    n = sint()

    '''
    # dp[i][j] 表示有 i 个左括号，j 个右括号的最大匹配
    # status[i][j] 表示根节点是否被选取
    # if i <= j: dp[i][j] = dp[i-1][j] + dp[i][j-1] * (i <= j - 1)
    # 如果两棵子树中有一个 status = 0，那么答案 + 1，status[i][j] = 1
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    status = [[0] * (n + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        dp[0][i] = (i + 1) // 2
        status[0][i] = i & 1

    for i in range(1, n + 1):
        for j in range(i, n + 1):
            dp[i][j] = dp[i - 1][j]
            if not status[i - 1][j]:
                dp[i][j] += 1
                status[i][j] = 1
            if i < j:
                dp[i][j] += dp[i][j - 1]
                if not status[i][j - 1] and not status[i][j]:
                    dp[i][j] += 1
                    status[i][j] = 1
            dp[i][j] %= MOD
    
    print(dp[-1][-1])
    '''

    # 滚动数组
    dp = [[0] * (n + 1) for _ in range(2)]
    status = [[0] * (n + 1) for _ in range(2)]
    for i in range(1, n + 1):
        dp[0][i] = (i + 1) // 2
        status[0][i] = i & 1
    cur = 0
    for i in range(1, n + 1):
        for j in range(i, n + 1):
            dp[cur ^ 1][j] = dp[cur][j]
            if not status[cur][j]:
                dp[cur ^ 1][j] += 1
                status[cur ^ 1][j] = 1
            else:
                status[cur ^ 1][j] = 0
            if i < j:
                dp[cur ^ 1][j] += dp[cur ^ 1][j - 1]
                if not dp[cur ^ 1][j] and not dp[cur ^ 1][j - 1]:
                    dp[cur ^ 1][j] += 1
                    status[cur ^ 1][j] = 1
            dp[cur ^ 1][j] %= MOD
        cur ^= 1
    print(dp[cur][-1])

solve()
