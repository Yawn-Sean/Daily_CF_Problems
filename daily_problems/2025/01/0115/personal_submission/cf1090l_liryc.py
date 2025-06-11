'''
https://codeforces.com/contest/1090/submission/301063688
1090L
2025/1/15 Y2
2000
??
'''
# ref

import sys
input = lambda: sys.stdin.readline().strip()

def init():
    t, n, a, b, k = map(int, input().split())
    return t, n, a, b, k

def solve(t, n, a, b, k):
    v2 = n >> 1 
    v1 = n - v2

    ans = min(t, (v1 * a + v2 * b) // k)
    if k > v1: 
        ans = min(ans, v2 * b // (k - v1))
    if k > v2: 
        ans = min(ans, v1 * a // (k - v2))

    return ans if k <= n else 0

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
