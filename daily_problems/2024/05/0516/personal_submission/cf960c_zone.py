def main(ac=FastIO()):
    """
    url: 
        question:   https://codeforces.com/problemset/problem/960/C
        submission: https://codeforces.com/contest/960/submission/261116873
    time: 187 ms
    """
    INF = 10 ** 17
    n, d = ac.read_list_ints() 
    ans = []
    cnt = INF 
    while cnt + len(ans) >= 10000:
        m = 0 
        while (1 << m) - 1 < n: m += 1 
        if (1 << m) - 1 > n: m -= 1 
        cnt = n - (1 << m) + 1
        ans += [INF] * m 
        n -= (1 << m) - 1
        INF -= d
    ans += [i * d for i in range(1, cnt + 1)]
    print(len(ans))
    print(*ans)
