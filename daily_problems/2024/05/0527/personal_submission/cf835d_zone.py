def main(ac=FastIO()):
    """
    url: 
        problem:    https://codeforces.com/problemset/problem/835/D
        submission: https://codeforces.com/contest/835/submission/262839560
    time: 733 ms
    """
    s = ac.read_str()
    n = len(s)
    dp = [0] * (n * n)

    def get_idx(i: int, j: int) -> int:
        return i * n + j 

    for i in range(n): 
        for j in range(i + 1):
            dp[get_idx(i, j)] = 1
    for i in range(n - 1, -1, -1):
        for j in range(i + 1, n):
            if s[i] == s[j] and dp[get_idx(i + 1, j - 1)]: 
                dp[get_idx(i, j)] = dp[get_idx(i, i + (j - i + 1) // 2 - 1)] + 1 
            else:
                dp[get_idx(i, j)] = 0 
    ans = [0] * n 
    for i in range(n):
        for j in range(i, n):
            fin = dp[get_idx(i, j)]
            if fin: 
                ans[fin - 1] += 1 
    # for i in range(0, n * n, n):
    #     print(*dp[i: i + n])
    for i in range(n - 2, -1, -1):
        ans[i] += ans[i + 1]
    print(*ans)
