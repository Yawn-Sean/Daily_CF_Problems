'''
https://codeforces.com/gym/106414/submission/373578574
prefix + suffix, 2nd max
'''
def solve(n: int, a: list[int]) -> int:
    if all(x == a[0] for x in a):
        return 0
    cn = Counter()
    st, sm1, sm2 = [0] * n, [0] * n, [0] * n
    t, m1, m2 = a[-1], 0, 0
    for i in range(n - 1, -1, -1):
        x = a[i]
        m = cn[x] = cn[x] + 1
        if x == t:
            m1 = m
        elif m > m1:
            t, m1, m2 = x, m, m1
        elif m > m2:
            m2 = m
        st[i], sm1[i], sm2[i] = t, m1, m2
    ans = 0
    t, m1, m2 = a[0], 0, 0
    cn = Counter()
    for i in range(n - 1):
        x = a[i]
        m = cn[x] = cn[x] + 1
        if x == t:
            m1 = m
        elif m > m1:
            t, m1, m2 = x, m, m1
        elif m > m2:
            m2 = m        
        if t == st[i + 1]:
            if sm2[i + 1] > 0:
                ans = max(ans, m1 + sm2[i + 1])
            if m2 > 0:
                ans = max(ans, m2 + sm1[i + 1])
        else:
            ans = max(ans, m1 + sm1[i + 1])
    return ans