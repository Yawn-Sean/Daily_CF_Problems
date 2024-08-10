'''
https://codeforces.com/contest/1321/submission/267832442
1321 C
2024/6/28
1600
string, brute force
'''

from itertools import groupby

def init():
    n = int(input())
    s = input()
    return n, s

def solve(n: int, s: str) -> int:
    a = []
    for k, g in groupby(s):
        c = sum(1 for _ in g)
        a.append((ord(k) - 97, c))
    ans = 0
    for k in range(25, 0, -1):
        for i in range(len(a) - 1, -1, -1):
            if a[i][0] == k and ((i > 0 and a[i - 1][0] == k - 1) or (i < len(a) - 1 and a[i + 1][0] == k - 1)):
                ans += a[i][1]
                a.pop(i)
        for i in range(len(a) - 1, 0, -1):
            if a[i][0] == a[i - 1][0]:
                a[i - 1] = (a[i][0], a[i - 1][1] + a[i][1])
                a.pop(i)
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
