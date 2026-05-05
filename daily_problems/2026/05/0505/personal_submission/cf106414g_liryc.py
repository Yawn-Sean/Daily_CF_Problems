'''
https://codeforces.com/gym/106414/submission/373563708
2026/5/5 Y1
1400
prefix + suffix, 2nd max
'''

from sys import stdin
from collections import Counter
input = lambda: stdin.readline().strip()

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

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
            ans = max(ans, m1 + sm2[i + 1], m2 + sm1[i + 1])
        else:
            ans = max(ans, m1 + sm1[i + 1])
    return ans

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)
