'''
https://codeforces.com/contest/1278/submission/278501769
1278 C
2024/8/28 Y1
1700
prefix sum
'''

import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = list(map(int, input().split()))
    return n, a

def solve(n: int, a: list[int]) -> int:
    n2 = a.count(2)
    n1 = n * 2 - n2
    target = n2 - n1
    di = {}
    di[0] = -1
    s, ans = 0, n << 1
    for i, x in enumerate(a):
        s += x * 2 - 3
        if i < n:
            di[s] = i
        if i >= n - 1:
            ps = s - target
            if ps in di:
                ans = min(ans, i - di[ps])
    return ans

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)
