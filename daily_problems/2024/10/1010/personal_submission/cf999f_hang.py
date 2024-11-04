
def main():
    n,k  = map(int,input().split())
    c = list(map(int,input().split()))
    f = list(map(int,input().split()))
    h = [0] + list(map(int,input().split()))
    color_cnt = [0] * (10 ** 5 + 2)
    for x in c:
        color_cnt[x] += 1
    player_cnt = [0] * (10 ** 5 + 2)
    for x in f:
        player_cnt[x] += 1
    dp = [[0] * (n * k + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, n * k + 1):
            for x in range(k+1):
                if j - x >= 0:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + h[x])
    ans = 0
    for i in range(10 ** 5 + 1):
        ans += dp[player_cnt[i]][color_cnt[i]]
    print(ans)
             
main()