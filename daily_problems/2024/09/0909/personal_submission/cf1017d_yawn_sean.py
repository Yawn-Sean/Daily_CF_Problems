# Submission link: https://codeforces.com/contest/1017/submission/280382327
def main():
    n, m, q = MII()
    values = LII()

    cnt = [0] * (1 << n)
    for _ in range(m):
        s = I()
        msk = 0
        for i in range(n):
            msk = msk * 2 + int(s[i])
        cnt[msk] += 1

    dp = [0] * (1 << n)
    for i in range(1, 1 << n):
        x = i & -i
        dp[i] = dp[i - x] + values[n - x.bit_length()]

    ans = [[0] * (1 << n) for _ in range(101)]
    v = (1 << n) - 1
    for x in range(1 << n):
        for y in range(1 << n):
            if dp[v - (x ^ y)] <= 100:
                ans[dp[v - (x ^ y)]][x] += cnt[y]
        for y in range(100):
            ans[y + 1][x] += ans[y][x]

    outs = []
    for _ in range(q):
        s, k = LI()
        k = int(k)
        
        msk = 0
        for i in range(n):
            msk = msk * 2 + int(s[i])
        
        outs.append(ans[k][msk])

    print('\n'.join(map(str, outs)))