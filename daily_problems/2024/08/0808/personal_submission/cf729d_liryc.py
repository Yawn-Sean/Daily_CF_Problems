'''
https://codeforces.com/contest/729/submission/275225462
729D
2024/8/8 Y1
1700
constructive
每一枪最多只能封住一艘船的位置，所以直接贪心，一直封直到剩下船的位置不足a艘
'''

from itertools import groupby

def init():
    n, a, b, k = map(int, input().split())
    s = input()
    return n, a, b, k, s

def solve(n, a, b, k, s):
    cn = [(k == '0', sum(1 for _ in g)) for k, g in groupby(s)]
    m = sum(c // b for k, c in cn if k) - a + 1
    ans = []
    i = 0
    for k, c in cn:
        if k:
            j = 0
            while c - j >= b:
                j += b
                ans.append(i + j)
                if len(ans) == m:
                    return ans
        i += c
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(len(ans))
    print(*ans)
