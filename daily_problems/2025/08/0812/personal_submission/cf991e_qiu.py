Com = [[0] * 20 for _ in range(20)]


def init():
    for i in range(20):
        Com[i][0] = Com[i][i] = 1
        for j in range(1, i):
            Com[i][j] = Com[i - 1][j] + Com[i - 1][j - 1]


def solve():
    s = input().strip()
    cnt = [0] * 10
    low = 0
    for ch in s:
        d = int(ch)
        cnt[d] += 1
        if cnt[d] == 1:
            low += 1

    ans = 0
    for length in range(low, len(s) + 1):
        dp = [0] * (length + 1)
        dp[0] = 1
        for i in range(10):
            if cnt[i]:
                temp = [0] * (length + 1)
                for j in range(length, -1, -1):
                    for k in range(1, min(length - j, cnt[i]) + 1):
                        less = length - j
                        if i == 0:
                            less -= 1
                        if less < k:
                            break
                        temp[j + k] += dp[j] * Com[less][k]
                dp = temp
        ans += dp[length]

    print(ans)


if __name__ == "__main__":
    init()
    t = 1
    for _ in range(t):
        solve()
