def main(ac=FastIO()):
    """
    url: 
        problem: https://codeforces.com/problemset/problem/1954/D
        submission: https://codeforces.com/contest/1954/submission/262852178
    time: 452 ms
    """
    n = ac.read_int()
    a = ac.read_list_ints()
    MOD = 998244353
    a.sort() 
    dp = [0] * (sum(a) + 1)
    ans = cur_sum = 0 
    dp[0] = 1
    for num in a: 
        for x in range(cur_sum, -1, -1):
            ans = (ans + dp[x] * max((x + num + 1) // 2, num)) % MOD
            dp[x + num] = (dp[x + num] + dp[x]) % MOD 
        cur_sum += num 
    print(ans)
