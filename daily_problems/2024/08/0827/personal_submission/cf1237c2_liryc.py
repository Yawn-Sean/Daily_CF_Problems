'''
https://codeforces.com/contest/1237/submission/278345424
1237 C2
2024/8/27 Y2
1900
sorting
'''

import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = []
    for _ in range(n):
        x, y, z = map(int, input().split())
        a.append((x, y, z))
    return n, a

def solve(n: int, a):
    ia = list(range(n))
    ia.sort(key=lambda i: a[i])
    stk = []
    ans = []
    for i in ia:
        x, y, z = a[i]
        if stk:
            i0 = stk[-1]
            x0, y0, z0 = a[i0]
            if x == x0:
                if y == y0:
                    stk.pop()
                    ans.append(f"{i + 1} {i0 + 1}")
                else:
                    while len(stk) >= 2 and a[stk[-2]][0] == x0:
                        k = stk.pop()
                        j = stk.pop()
                        ans.append(f"{k + 1} {j + 1}")
                    stk.append(i)
            else:
                while len(stk) >= 2:
                    k = stk.pop()
                    j = stk.pop()
                    ans.append(f"{k + 1} {j + 1}")
                stk.append(i)
        else:
            stk.append(i)
    while stk:
        k = stk.pop()
        j = stk.pop()
        ans.append(f"{k + 1} {j + 1}")
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(*ans, sep='\n')
