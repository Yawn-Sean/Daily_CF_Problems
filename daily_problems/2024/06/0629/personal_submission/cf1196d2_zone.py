def main(ac=FastIO()):
    """
    url: https://codeforces.com/problemset/problem/1196/D2
    submission: https://codeforces.com/contest/1196/submission/267937175
    """
    for _ in range(ac.read_int()):
        n, k = ac.read_list_ints()
        s = ac.read_str()
        ans = k 
        pattern = "RGB" * n 
        for l in range(3):
            res = sum(x != y for x, y in zip(pattern[l: l + k], s[:k]))
            for i in range(n - k):
                ans = min(ans, res)
                res += (s[i + k] != pattern[(l + i + 1) % 3 + k - 1]) - (s[i] != "RGB"[(l + i) % 3])
            ans = min(ans, res)
        ac.st(ans)
