'''
https://codeforces.com/problemset/submission/254/324592754
'''
# string, counter
def solve(s: str, t: str) -> tuple[int, str]:
    n = len(s)
    c_s, c_t = Counter(s), Counter(t)
    d_st, d_ts = c_s - c_t, c_t - c_s
    if not d_st:
        return [0, s]
    ans, ans_a = 0, [""] * n
    next_ord = 65
    while next_ord < 91 and not d_ts[chr(next_ord)]:
        next_ord += 1
    for i in range(n):
        if next_ord >= 91:
            ans_a[i] = s[i]
            continue
        x, y = s[i], chr(next_ord)
        if d_st[x] and (x > y or not c_t[x]):
            ans += 1
            ans_a[i] = y
            d_st[x] -= 1
            d_ts[y] -= 1
            c_t[y] -= 1
            while next_ord < 91 and not d_ts[y]:
                next_ord += 1
                y = chr(next_ord)
        else:
            ans_a[i] = x
            c_t[x] -= 1
    return [ans, ''.join(ans_a)]
