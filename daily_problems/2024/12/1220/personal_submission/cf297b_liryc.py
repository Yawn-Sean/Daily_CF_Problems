'''
https://codeforces.com/problemset/submission/297/297449557
297B
2024/12/20 Y1
1600
constructive
'''
# for each A's fish x, there must be a B's fish y >= x to catch it
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    return n, m, k, a, b

def solve(n, m, k, a, b):
    if len(a) > len(b):
        return True
    a.sort()
    b.sort()
    j = 0
    for x in a:
        while j < m and b[j] < x:
            j += 1
        if j == m:
            return True
        else:
            j += 1
    return False

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print("YES" if ans else "NO")
