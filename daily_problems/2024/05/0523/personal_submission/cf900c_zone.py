def main(ac=FastIO()):
    """
    url: 
        question:   https://codeforces.com/problemset/problem/900/C
        submission: https://codeforces.com/contest/900/submission/262257925
    time: 171 ms
    """
    n = ac.read_int()
    a = ac.read_list_ints()
    if n <= 2: 
        print(1)
        return 
    cnt = [0] * n
    mx, md = 0, 1
    if a[mx] < a[md]: md, mx = 0, 1 
    if mx == 1: 
        cnt[a[1] - 1] -= 1 
        cnt[a[0] - 1] -= 1
    for i, x in enumerate(a[2:], 2):
        if x > a[mx]: 
            cnt[x - 1] -= 1 
            mx, md = i, mx 
        elif a[md] < x:
            md = i 
            cnt[a[mx] - 1] += 1 
    print(cnt.index(max(cnt)) + 1)
