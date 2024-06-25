def main(ac=FastIO()):
    """
    url:
        question:   https://codeforces.com/problemset/problem/914/C
        submission: https://codeforces.com/contest/914/submission/260885290
    time: 843 ms
    """
    MOD = 10 ** 9 + 7
    s = ac.read_str()
    k = ac.read_int()
    n = len(s)
    if k == 0: 
        print(1)
        return 
    fin = set()
    if k != 1:
        for x in range(1, n + 1):
            c   = x
            cnt = (x != 1)
            while c > 1: 
                cnt += 1 
                c    = bin(c).count('1')
            if cnt == k and c == 1:
                fin.add(x)
    else: fin.add(1)
    @lru_cache(None) 
    def dp(i: int, cnt: int, is_limit: bool, is_num: bool) -> int: 
        if i == n: return int(cnt in fin and is_num)
        res = 0 
        if not is_num: 
            res = dp(i + 1, cnt, False, False)
        low = 0 if is_num else 1 
        up  = int(s[i]) if is_limit else 1
        for d in range(low, up + 1):
            res += dp(i + 1, cnt + (d == 1), is_limit and d == up, True)
        return res % MOD
    print(dp(0, 0, True, False) - (k == 1))
