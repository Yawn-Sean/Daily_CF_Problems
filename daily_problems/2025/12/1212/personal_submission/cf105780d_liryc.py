'''
2025/12/12 Y1
'''

from sys import stdin
input = lambda: stdin.readline().strip()

def init():
    n = int(input())
    a = [[0, 0] for _ in range(n)]
    for i in range(n):
        a[i][:] = map(int, input().split())
    return n, a

def solve(n: int, a: list[list[int]]) -> int:
    hs = set(a)
    
    ans = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            x1, y1 = a[i]
            x2, y2 = a[j]
            dx = x2 - x1
            dy = y2 - y1
            if (x1 + dx - dy, y1 + dx + dy) in hs and (x1 - dy, y1 + dx) in hs:
                ans += 1
            if (x1 + dy, y1 - dx) in hs and (x1 + dx + dy, y1 + dy - dx) in hs:
                ans += 1
    return ans >> 2    

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)

