'''
https://codeforces.com/contest/1082/submission/282169301
1082B
2024/9/21 Y1
1600
string / 分类讨论
本题与力扣1156相似
'''

import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    s = input()
    return n, s

def solve(n: int, s: str):
    m1 = s.count('G')
    m2 = 0
    i, k = 0, 0
    for j, c in enumerate(s):
        if c != 'G':
            k += 1
        while k > 1:
            if s[i] != 'G':
                k -= 1
            i += 1
        m2 = max(m2, j - i + 1)

    return min(m1, m2)

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
