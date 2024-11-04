'''
https://codeforces.com/contest/1210/submission/282932242
1210B
2024/9/25 Y1
1700
Counter, bit set
'''

from collections import Counter
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    return n, a, b

def solve(n: int, a: list[int], b: list[int]):
    cn = Counter(a)
    vis = [False] * n

    ans = 0
    for k, c in cn.items():
        if c > 1:
            for i in range(n):
                if not vis[i] and a[i] & k == a[i]:
                    vis[i] = True
                    ans += b[i]
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
