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
    nums = ints()

    m = max(nums)
    cnt = [0] * (m + 1)
    for x in nums:
        cnt[x] += 1
    for i in range(m, 0, -1):
        cnt[i - 1] += cnt[i]

    factor = [[] for _ in range(m + 1)]
    
    for i in range(1, m + 1):
        for j in range(i, m + 1, i):
            factor[j].append(i)

    ans = 0
    for i in range(1, m + 1):
        res = 1
        k = len(factor[i])
        for j in range(1, k):
            res = res * pow(j, cnt[factor[i][j - 1]] - cnt[factor[i][j]], MOD) % MOD
        res = res * (pow(k, cnt[i], MOD) - pow(k - 1, cnt[i], MOD)) % MOD
        ans = (ans + res) % MOD
    print(ans)


solve()
