"""
problem url   : https://codeforces.com/problemset/problem/935/D
submission url: https://codeforces.com/contest/935/submission/283728627
"""

n, m = MII()
s1 = LII() 
s2 = LII() 

mod = 10 ** 9 + 7

tot = 0

c1, c2 = sum(x == 0 for x in s1), sum(x == 0 for x in s2)
c = pow(m, -c1, mod) * pow(m, -c2, mod) % mod
cnt = 1

for a, b in zip(s1, s2): 
    if a and b and a < b: 
        break 
    if a == 0 and b: 
        if m > b:
            tot += cnt * (m - b) * pow(m, c1 - 1, mod) * pow(m, c2, mod)
        c1 -= 1 
    elif b == 0 and a: 
        if a > 1: 
            tot += cnt * (a - 1) * pow(m, c1, mod) * pow(m, c2 - 1, mod)
        c2 -= 1 
    elif a == 0 and b == 0:
        tot += cnt * (m - 1) * m // 2 * pow(m, c1 - 1, mod) * pow(m, c2 - 1, mod)
        cnt *= m 
        c1 -= 1 
        c2 -= 1 
    elif a > b: 
        tot += cnt * pow(m, c1, mod) * pow(m, c2, mod)
        break 
    cnt %= mod 
    tot %= mod 
print((tot * c) % mod)
